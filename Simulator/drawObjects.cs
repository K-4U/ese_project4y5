using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulator {
    // 10mm = 1px 
    public class drawObject {
        public Rectangle loc;
        public Graphics g;
        public Pen p = Pens.Black;
        public drawObject(int x, int y, int w, int h) {
            this.loc = new Rectangle(x, y, w, h);
            //this.g = pb.CreateGraphics();
        }

        virtual public void draw(Graphics g) { }

        //Returns if it should be redrawn
        virtual public bool timer(int ms) { return false; }

    }

    public class drawRoomba : drawObject {
        private const int roombaWidthInPx = 26;
        private const int roombaHeightInPx = 26;
        private const int WHEELBASE = 26;
        private const int BUFFERMAX = 100;
        private new Pen p = Pens.Blue;
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

        private double bufferAngle;

        public drawRoomba(int x, int y, int angle) : base(x, y, roombaWidthInPx, roombaHeightInPx) {
            this.innerLoc = new Rectangle(base.loc.X + 2, base.loc.Y + 2, roombaWidthInPx - 4, roombaHeightInPx - 4);
            this.angle = angle;
            this.leftWheel.pos.X = x;
            this.leftWheel.pos.Y = y + (roombaHeightInPx / 2);

            this.rightWheel.pos.X = x + roombaWidthInPx;
            this.rightWheel.pos.Y = y + (roombaHeightInPx / 2);

        }

        public override void draw(Graphics g) {
            /*Rectangle newLoc = new Rectangle();
            newLoc.X = base.loc.X - (roombaWidthInPx / 2);
            newLoc.Y = base.loc.Y - (roombaHeightInPx / 2);
            newLoc.Width = roombaWidthInPx;
            newLoc.Height = roombaHeightInPx;
            Rectangle newInnerLoc = new Rectangle();
            newInnerLoc.Y = newLoc.Y + 2;
            newInnerLoc.X = newLoc.X + 2;
            newInnerLoc.Width = roombaWidthInPx - 4;
            newInnerLoc.Height = roombaHeightInPx - 4;*/

            //g.DrawArc(this.p, base.loc, 0, 360);
            //g.DrawArc(this.p, this.innerLoc, this.angle - 22, 45);
            //g.DrawRectangle(this.p, base.loc);
            //g.DrawLine(Pens.Black, base.loc.X, base.loc.Y + (roombaHeightInPx / 2), base.loc.X + roombaWidthInPx, base.loc.Y + (roombaHeightInPx / 2));
            //g.DrawLine(Pens.Black, base.loc.X, base.loc.Y, base.loc.X , base.loc.Y + roombaHeightInPx);

            PointF wheelPos = degreesToXY(this.angle+90, 15);
            g.DrawLine(Pens.Green, this.leftWheel.pos.X - (wheelPos.X/2), this.leftWheel.pos.Y - (wheelPos.Y/2), this.leftWheel.pos.X + (wheelPos.X/2), this.leftWheel.pos.Y + (wheelPos.Y/2));
            g.DrawLine(Pens.Red, this.rightWheel.pos.X - (wheelPos.X / 2), this.rightWheel.pos.Y - (wheelPos.Y / 2), this.rightWheel.pos.X + (wheelPos.X / 2), this.rightWheel.pos.Y + (wheelPos.Y / 2));
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
                    double d = Math.Abs(this.leftWheel.speed - this.rightWheel.speed) / 2;
                    double f = (d / BUFFERMAX) / WHEELBASE;
                    double angleAdj = (Math.Tanh(f) * (180 / Math.PI));
                    angleAdj = angleAdj * 2;
                    /*this.bufferAngle += angleAdj;

                    if (this.bufferAngle >= 1) {
                        angleAdj = this.bufferAngle;
                        this.bufferAngle = this.bufferAngle % 1;
                    } else if (this.bufferAngle <= -1) {
                        angleAdj = this.bufferAngle;
                        this.bufferAngle = this.bufferAngle % 1;
                    }*/

                    this.angle -= (int)angleAdj;
                    /*if (this.angle > 360) {
                        this.angle -= 360;
                    } else if (this.angle < 0) {
                        this.angle = 360 - this.angle;
                    }*/

                    //angleAdj = 1;


                    //float componentAngle = 90 - ((180 - ((float)angleAdj)) / 2);
                    PointF point = degreesToXY((float)this.angle, (float)WHEELBASE);

                    int baseSpeed = -leftWheel.speed;
                    if (rightWheel.speed > leftWheel.speed) {
                        baseSpeed = rightWheel.speed - (int)(d * 2);
                        /*PointF pointBoth = degreesToXY((float)this.angle, (float)baseSpeed);

                        this.leftWheel = doBuffer(this.leftWheel, pointBoth);*/
                        this.rightWheel.pos.X = this.leftWheel.pos.X + (int)point.X;
                        this.rightWheel.pos.Y = this.leftWheel.pos.Y + (int)point.Y;

                    } else if (rightWheel.speed < leftWheel.speed) {
                        baseSpeed = leftWheel.speed - (int)(d * 2);
                        /*PointF pointBoth = degreesToXY((float)this.angle, (float)baseSpeed);

                        this.rightWheel = doBuffer(this.rightWheel, pointBoth);*/

                        this.leftWheel.pos.X = this.rightWheel.pos.X - (int)point.X;
                        this.leftWheel.pos.Y = this.rightWheel.pos.Y - (int)point.Y;

                    }


                    PointF pointBoth = degreesToXY((float)this.angle-90, (float)baseSpeed);
                    this.leftWheel = doBuffer(this.leftWheel, pointBoth);
                    this.rightWheel = doBuffer(this.rightWheel, pointBoth);

                    //this.leftWheel = doBuffer(this.leftWheel, (float)angleAdj);
                    //this.rightWheel = doBuffer(this.rightWheel, (float)angleAdj);


                    /*
                    base.loc.Y += speedY;
                    base.loc.X += speedX;

                    this.innerLoc.Y = base.loc.Y + 2;
                    this.innerLoc.X = base.loc.X + 2;
                     * */
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
