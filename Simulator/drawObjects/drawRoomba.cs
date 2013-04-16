using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulator.drawObjects {
	public class drawRoomba : drawObject {
		private const int roombaWidthInPx = 26;
		private const int roombaHeightInPx = 26;
		private const double WHEELBASE = 25.8;
		private const int WHEELWIDTH = 10;
		private const double TIMEFACTOR = 0.01;
		private const bool drawPath = true;
		private const int MAXLENGTHOFPATH = 2500;

		struct wheel {
			public double speed;
			public PointF pos;
			public Pen p;
		}
		
		private PointF centerPoint;
		private List<PointF> paths;

		private new Pen p = Pens.Blue;
		private double angle;
		private RectangleF innerLoc;
		
		
		private bool isDriving = false;
		private wheel leftWheel;
		private wheel rightWheel;
		private PointF wheelPos;

		public drawRoomba(int x, int y, int angle)
			: base(x, y, roombaWidthInPx, roombaHeightInPx) {
			this.innerLoc = new RectangleF(base.loc.X + 2, base.loc.Y + 2, roombaWidthInPx - 4, roombaHeightInPx - 4);
			this.angle = angle;
			this.leftWheel.pos.X = x;
			this.leftWheel.pos.Y = y + (roombaHeightInPx / 2);
			this.leftWheel.p = Pens.Green;

			this.rightWheel.pos.X = x + roombaWidthInPx;
			this.rightWheel.pos.Y = y + (roombaHeightInPx / 2);
			this.rightWheel.p = Pens.Red;

			this.wheelPos = degreesToXY(this.angle + 90, WHEELWIDTH);

			this.centerPoint.X = base.loc.X + (base.loc.Width / 2);
			this.centerPoint.Y = base.loc.Y + (base.loc.Height / 2);


			this.paths = new List<PointF>();
		}

		public override void draw(Graphics g) {
			//Do not touch this!
			g.DrawArc(this.p, base.loc, 0, 360);
			g.DrawArc(this.p, this.innerLoc, (int)(this.angle - 90) - 22, 45);
			if (drawPath) {
				if (this.paths.Count > 1) {
					g.DrawLines(Pens.Red, this.paths.ToArray());
				}
			}

			//Comment this for no wheels
			/*g.DrawLine(this.leftWheelPen, this.leftWheel.pos.X - (this.wheelPos.X / 2), this.leftWheel.pos.Y - (this.wheelPos.Y / 2),
				this.leftWheel.pos.X + (this.wheelPos.X / 2), this.leftWheel.pos.Y + (this.wheelPos.Y / 2));
			g.DrawLine(this.rightWheelPen, this.rightWheel.pos.X - (this.wheelPos.X / 2), this.rightWheel.pos.Y - (this.wheelPos.Y / 2),
				this.rightWheel.pos.X + (this.wheelPos.X / 2), this.rightWheel.pos.Y + (this.wheelPos.Y / 2));

			//Comment this for no axis
			g.DrawLine(this.p, this.leftWheel.pos, this.rightWheel.pos);*/
		}

		public override void _reset() {
			this.setSpeed(0, 0);
			this.centerPoint.X = base.loc.X;
			this.centerPoint.Y = base.loc.Y;
			calculateTravelDistance();
		}

		private static PointF degreesToXY(double degrees, double radius) {
			double dividor = Math.PI / 180.0;
			double radians = degrees * dividor;
			PointF result = new PointF();
			result.X = (float) (Math.Cos(radians) * radius);
			result.Y = (float) (Math.Sin(radians) * radius);
			return result;
		}

		private void doAdd(ref PointF target, PointF toAdd) {
			target.X += toAdd.X;
			target.Y += toAdd.Y;
		}

		private void calculateTravelDistance() {
			//Now, we calculate the position that one of the wheels move
			double leftWheelSpeed = Math.Abs(leftWheel.speed);
			double rightWheelSpeed = Math.Abs(rightWheel.speed);

			double rotationPointOnAxis = 0;
			double smallestSpeedAbs = (leftWheelSpeed < rightWheelSpeed ? leftWheelSpeed : rightWheelSpeed);
			double biggestSpeedAbs = (smallestSpeedAbs == leftWheelSpeed ? rightWheelSpeed : leftWheelSpeed);

			if (leftWheelSpeed != rightWheelSpeed) {
				double negativeOrPositive = (rightWheelSpeed > leftWheelSpeed ? -1 : 1);
				rotationPointOnAxis = negativeOrPositive * (100 - ((smallestSpeedAbs / biggestSpeedAbs) * 100));
			}

			rotationPointOnAxis = (double) ( ( ( (double)rotationPointOnAxis + 100) / 200) * WHEELBASE);

			double dDistance = rightWheel.speed * TIMEFACTOR;

			//Calculate the angle at which the roomba is turning. angleAdj.
			//We know that the difference between the wheels will give us a
			//Triangle with equivalent legs
			//When we aply some magic formulas to that(see below)
			//We get the angle the roomba has rotated
			double d = dDistance / 2;
			double f = (d / rotationPointOnAxis);
			double sinCalc = Math.Asin(f);
			double angleAdj = ((sinCalc / Math.PI) * 180);
			angleAdj = angleAdj * 2;

			//We then add that to the global angle
			if (this.leftWheel.speed < 0 || this.rightWheel.speed > 0) {
				this.angle -= angleAdj;
			} else if (this.leftWheel.speed > 0 || this.rightWheel.speed < 0) {
				this.angle += angleAdj;
			}

			//Basespeed + diff and angle
			//Centerpoint stays on the same spot on the axis
			//This means that it travels the distance that both wheels travel on their own
			//Including the HALF of the distance the fastest wheel moves away.
			double distanceTraveled = ((leftWheel.speed + rightWheel.speed) / 2); //Divided by 100 because speed is in seconds, and this function is in 0.01 seconds
			PointF newPoint = degreesToXY((float)this.angle - 90, distanceTraveled);

			doAdd(ref this.centerPoint, newPoint);
			base.loc.X = this.centerPoint.X - (base.loc.Width / 2);
			base.loc.Y = this.centerPoint.Y - (base.loc.Height / 2);

			//Add the current location to a list.
			//That way we can see where we have been :D
			//YAY :D
			if (this.paths.Count == 0) {
				//Always add
				this.paths.Add(centerPoint);
			} else if (this.paths.Count > 0) {
				if (!this.paths[this.paths.Count - 1].Equals(centerPoint)) {
					this.paths.Add(centerPoint);
				}

				if (this.paths.Count > MAXLENGTHOFPATH) {
					this.paths.RemoveAt(0);
				}
			}

			//Innerloc is a rectangle which holds a smaller circle.
			//This circle shows you which direction the roomba is heading
			this.innerLoc = new RectangleF(base.loc.X + 2, base.loc.Y + 2, roombaWidthInPx - 4, roombaHeightInPx - 4);

			//wheelPos will hold a small line that shows the direction of the wheels
			this.wheelPos = degreesToXY(this.angle + 90, WHEELWIDTH);
		}

		public override bool timer(int ms) {
			bool doRedraw = false;
			if (ms == 500) {

			} else if (ms == 10) {
				doRedraw = isDriving;
				if (this.isDriving) {
					calculateTravelDistance();
				}
			}
			return doRedraw;
		}

		public void setSpeed(int left, int right) {
			isDriving = (left != 0 || right != 0);
			this.leftWheel.speed = ((double)left / 10) *TIMEFACTOR; // Divided by 10 for the scale
			this.rightWheel.speed = ((double)right / 10) *TIMEFACTOR;
		}
	}
}
