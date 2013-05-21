using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulator.drawObjects {
	class drawTable : drawObject {
		private const int widthInPx = 260;
		private const int heightInPx = 260;
		private new Pen p = Pens.DarkBlue;

		public drawTable(int x, int y)
			: base(x, y, widthInPx, heightInPx) {

		}

		public override void draw(Graphics g) {
			g.DrawRectangle(this.p, Rectangle.Round(base.loc));
		}
	}
}

namespace Simulator.drawObjects {
    class drawPool : drawObject {
        private const int widthInPx = 150;
        private const int heightInPx = 3000;
        private Brush b = Brushes.Aquamarine;

        public drawPool(int x, int y)
            : base(x, y, widthInPx, heightInPx) {

        }

        public override void draw(Graphics g) {
            g.FillRectangle(this.b, Rectangle.Round(base.loc));
        }
    }
}
