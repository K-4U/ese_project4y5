using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulator {
    public class drawObject {
        public Rectangle loc;
        public Graphics g;
        public Pen p = Pens.Black;
        public drawObject(int x, int y, int w, int h, PictureBox pb) {
            this.loc = new Rectangle(x, y, w, h);
            this.g = pb.CreateGraphics();
        }

        virtual public void draw() { }

        virtual public void timer(int ms) { }

    }

    public class drawRoomba : drawObject {
        public drawRoomba(int x, int y, int w, int h, PictureBox pb) : base(x, y, w, h, pb) { }

        public override void draw() {
            base.g.DrawArc(base.p, base.loc, 0, 360);
        }
        public override void timer(int ms) {
            if (ms == 500) {

            }
        }
    }
}
