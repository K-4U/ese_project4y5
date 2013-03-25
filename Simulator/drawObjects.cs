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
        private const int WHEELBASE = 258;
        private new Pen p = Pens.Blue;
        private int angle;
        private Rectangle innerLoc;

        private bool isDriving = false;
        private int leftSpeed;
        private int rightSpeed;
        private int bufferX;
        private int bufferY;
        private double bufferAngle;

        public drawRoomba(int x, int y, int angle) : base(x, y, roombaWidthInPx, roombaHeightInPx) {
            this.innerLoc = new Rectangle(x + 2, y + 2, roombaWidthInPx - 4, roombaHeightInPx - 4);
            this.angle = angle-90;
        }

        public override void draw(Graphics g) {
            g.DrawArc(this.p, base.loc, 0, 360);
            g.DrawArc(this.p, this.innerLoc, this.angle - 22, 45);
        }

        public override bool timer(int ms) {
            bool doRedraw = false;
            if (ms == 500) {

            } else if (ms == 100) {
                doRedraw = isDriving;
                double d = (this.leftSpeed - this.rightSpeed);
                double f = d / WHEELBASE;
                double angleAdj = (Math.Tanh(f) * (180 / Math.PI));
                this.bufferAngle += angleAdj;

                if (this.bufferAngle >= 1) {
                    angleAdj = this.bufferAngle;
                    this.bufferAngle -= 1;
                } else if (this.bufferAngle <= -1) {
                    angleAdj = this.bufferAngle;
                    this.bufferAngle += 1;
                }

                this.angle += (int)angleAdj;

                int speedY = (int) (Math.Sin((double)(this.angle) * (double)(Math.PI / 180)) * ((this.leftSpeed + this.rightSpeed) / 2));
                int speedX = (int) (Math.Cos((double)(this.angle) * (double)(Math.PI / 180)) * ((this.leftSpeed + this.rightSpeed) / 2));
                bufferY += speedY;
                bufferX += speedX;

                speedY = speedY / 100;
                speedX = speedX / 100;

                if (bufferY >= 100) {
                    speedY = bufferY / 100;
                    bufferY -= 100;
                } else if (bufferY <= -100) {
                    speedY = bufferY / 100;
                    bufferY += 100;
                }

                if (bufferX >= 100) {
                    speedX = bufferX / 100;
                    bufferX -= 100;
                } else if (bufferX <= -100) {
                    speedX = bufferX / 100;
                    bufferX += 100;
                }

                base.loc.Y += speedY;
                base.loc.X += speedX;

                this.innerLoc.Y = base.loc.Y + 2;
                this.innerLoc.X = base.loc.X + 2;
            }
            return doRedraw;
        }

        public void setSpeed(int left, int right) {
            if (left != 0 || right != 0) {
                isDriving = true;
            } else {
                isDriving = false;
            }
            this.leftSpeed = left;
            this.rightSpeed = right;
        }
    }
}
