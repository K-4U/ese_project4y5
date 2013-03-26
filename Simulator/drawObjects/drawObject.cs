using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulator.drawObjects {
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
}
