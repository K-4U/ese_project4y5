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
		private const int WHEELBASE = 26;
		private const int BUFFERMAX = 100;
		private const int WHEELWIDTH = 10;
		private const bool drawPath = true;
		private const int MAXLENGTHOFPATH = 250;
		private List<Point> paths;
		private new Pen p = Pens.Blue;
		private Pen leftWheelPen = Pens.Green;
		private Pen rightWheelPen = Pens.Red;
		private int angle;
		private Rectangle innerLoc;

		struct wheel {
			public float bufferX;
			public float bufferY;
			public int speed;
			public Point pos;
		}

		private bool isDriving = false;
		private wheel leftWheel;
		private wheel rightWheel;
		private PointF wheelPos;

		public drawRoomba(int x, int y, int angle)
			: base(x, y, roombaWidthInPx, roombaHeightInPx) {
			this.innerLoc = new Rectangle(base.loc.X + 2, base.loc.Y + 2, roombaWidthInPx - 4, roombaHeightInPx - 4);
			this.angle = angle;
			this.leftWheel.pos.X = x;
			this.leftWheel.pos.Y = y + (roombaHeightInPx / 2);

			this.rightWheel.pos.X = x + roombaWidthInPx;
			this.rightWheel.pos.Y = y + (roombaHeightInPx / 2);

			this.wheelPos = degreesToXY(this.angle + 90, WHEELWIDTH);

			this.paths = new List<Point>();
		}

		public override void draw(Graphics g) {
			//Do not touch this!
			g.DrawArc(this.p, base.loc, 0, 360);
			g.DrawArc(this.p, this.innerLoc, (this.angle - 90) - 22, 45);
			if (drawPath) {
				if (this.paths.Count > 1) {
					g.DrawLines(Pens.Aqua, this.paths.ToArray());
				}
			}

			//Comment this for no wheels
			g.DrawLine(this.leftWheelPen, this.leftWheel.pos.X - (this.wheelPos.X / 2), this.leftWheel.pos.Y - (this.wheelPos.Y / 2),
				this.leftWheel.pos.X + (this.wheelPos.X / 2), this.leftWheel.pos.Y + (this.wheelPos.Y / 2));
			g.DrawLine(this.rightWheelPen, this.rightWheel.pos.X - (this.wheelPos.X / 2), this.rightWheel.pos.Y - (this.wheelPos.Y / 2),
				this.rightWheel.pos.X + (this.wheelPos.X / 2), this.rightWheel.pos.Y + (this.wheelPos.Y / 2));

			//Comment this for no axis
			g.DrawLine(this.p, this.leftWheel.pos, this.rightWheel.pos);
		}

		private static PointF degreesToXY(float degrees, float radius) {
			double dividor = Math.PI / 180.0;
			double radians = degrees * dividor;
			PointF result = new PointF();
			result.X = ((float)Math.Cos(radians) * radius);
			result.Y = ((float)Math.Sin(radians) * radius);
			return result;
		}

		private wheel doBuffer(wheel target, PointF toAdd) {
			target.bufferX += toAdd.X;
			target.bufferY += toAdd.Y;

			toAdd.X = toAdd.X / BUFFERMAX;
			toAdd.Y = toAdd.Y / BUFFERMAX;

			if (target.bufferX >= BUFFERMAX) {
				toAdd.X = target.bufferX / BUFFERMAX;
				target.bufferX -= BUFFERMAX;
			} else if (target.bufferX <= -BUFFERMAX) {
				toAdd.X = target.bufferX / BUFFERMAX;
				target.bufferX += BUFFERMAX;
			}

			if (target.bufferY >= BUFFERMAX) {
				toAdd.Y = target.bufferY / BUFFERMAX;
				target.bufferY -= BUFFERMAX;
			} else if (target.bufferY <= -BUFFERMAX) {
				toAdd.Y = target.bufferY / BUFFERMAX;
				target.bufferY += BUFFERMAX;
			}

			target.pos.X -= (int)toAdd.X;
			target.pos.Y -= (int)toAdd.Y;

			return target;
		}

		public override bool timer(int ms) {
			bool doRedraw = false;
			if (ms == 500) {

			} else if (ms == 100) {
				doRedraw = isDriving;
				if (this.isDriving) {
					//Calculate the angle at which the roomba is turning. angleAdj.
					//We know that the difference between the wheels will give us a
					//Triangle with equivalent legs
					//When we aply some magic formulas to that(see below)
					//We get the angle the roomba has rotated
					double d = Math.Abs(this.leftWheel.speed - this.rightWheel.speed) / 2;
					double f = (d / BUFFERMAX) / WHEELBASE;
					double angleAdj = (Math.Tanh(f) * (180 / Math.PI));
					angleAdj = angleAdj * 2;

					//We then add that to the global angle
					if (this.leftWheel.speed < 0 || this.rightWheel.speed > 0) {
						this.angle -= (int)angleAdj;
					} else if(this.leftWheel.speed > 0 || this.rightWheel.speed < 0) {
						this.angle += (int)angleAdj;
					}

					//Now, we calculate the position that one of the wheels move
					PointF point = degreesToXY((float)this.angle, (float)WHEELBASE);

					int leftWheelSpeed = Math.Abs(leftWheel.speed);
					int rightWheelSpeed = Math.Abs(rightWheel.speed);

					int rotationPointOnAxis = 0;

					if (leftWheelSpeed != rightWheelSpeed) {
						int smallestSpeed = (leftWheelSpeed < rightWheelSpeed ? leftWheelSpeed : rightWheelSpeed);
						int biggestSpeed = (smallestSpeed == leftWheelSpeed ? rightWheelSpeed : leftWheelSpeed);
						int negativeOrPositive = (rightWheelSpeed > leftWheelSpeed ? -1 : 1);

						rotationPointOnAxis = negativeOrPositive * (100 - ((smallestSpeed / biggestSpeed) * 100));
					}

					rotationPointOnAxis = (int)Math.Round((((double)rotationPointOnAxis + 100) / 200) * WHEELBASE);


					/*					
					//BaseSpeed is the speed at which BOTH of the wheels should have traveled
					//before the other one decided to go a little faster
					int baseSpeed = -leftWheel.speed;
					if (rightWheelSpeed > leftWheelSpeed) {
						baseSpeed = rightWheel.speed - (int)(d * 2);
						this.rightWheel.pos.X = this.leftWheel.pos.X + (int)point.X;
						this.rightWheel.pos.Y = this.leftWheel.pos.Y + (int)point.Y;

					} else if (rightWheelSpeed < leftWheelSpeed) {
						baseSpeed = leftWheel.speed - (int)(d * 2);
						this.leftWheel.pos.X = this.rightWheel.pos.X - (int)point.X;
						this.leftWheel.pos.Y = this.rightWheel.pos.Y - (int)point.Y;
					}
					if (rightWheel.speed == 0 || leftWheel.speed == 0) {
						baseSpeed = 0;
					}

					//Now, we calculate where both of the wheels should be, given the basespeed
					PointF pointBoth = degreesToXY((float)this.angle - 90, (float)baseSpeed);
					this.leftWheel = doBuffer(this.leftWheel, pointBoth);
					this.rightWheel = doBuffer(this.rightWheel, pointBoth);
					*/

					//Here we calculate the X and Y for drawing
					//It is the top left corner of the roomba
					PointF diff = new PointF();
					if (this.leftWheel.pos.X > this.rightWheel.pos.X) {
						diff.X = ((leftWheel.pos.X - rightWheel.pos.X) / 2);
						base.loc.X = (int)rightWheel.pos.X + (int)diff.X;
						base.loc.X -= (roombaWidthInPx / 2);
					} else {
						diff.X = ((rightWheel.pos.X - leftWheel.pos.X) / 2);
						base.loc.X = (int)leftWheel.pos.X + (int)diff.X;
						base.loc.X -= (roombaWidthInPx / 2);
					}

					if (this.leftWheel.pos.Y > this.rightWheel.pos.Y) {
						diff.Y = ((leftWheel.pos.Y - rightWheel.pos.Y) / 2);
						base.loc.Y = (int)rightWheel.pos.Y + (int)diff.Y;
						base.loc.Y -= (roombaHeightInPx / 2);
					} else {
						diff.Y = ((rightWheel.pos.Y - leftWheel.pos.Y) / 2);
						base.loc.Y = (int)leftWheel.pos.Y + (int)diff.Y;
						base.loc.Y -= (roombaHeightInPx / 2);
					}

					//And the center point, so that we can log the points where the roomba has been
					Point center = new Point(base.loc.X + (base.loc.Width / 2), base.loc.Y + (base.loc.Height / 2));
					if (this.paths.Count == 0) {
						//Always add
						this.paths.Add(center);
					} else if (this.paths.Count > 0) {
						if (!this.paths[this.paths.Count - 1].Equals(center)) {
							this.paths.Add(center);
						}

						if (this.paths.Count > MAXLENGTHOFPATH) {
							this.paths.RemoveAt(0);
						}
					}

					//Innerloc is a rectangle which holds a smaller circle.
					//This circle shows you which direction the roomba is heading
					this.innerLoc = new Rectangle(base.loc.X + 2, base.loc.Y + 2, roombaWidthInPx - 4, roombaHeightInPx - 4);

					//wheelPos will hold a small line that shows the direction of the wheels
					this.wheelPos = degreesToXY(this.angle + 90, WHEELWIDTH);
				}
			}
			return doRedraw;
		}

		public void setSpeed(int left, int right) {
			if (left != 0 || right != 0) {
				isDriving = true;
			} else {
				isDriving = false;
			}
			this.leftWheel.speed = left;
			this.rightWheel.speed = right;
		}
	}
}
