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
