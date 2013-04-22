namespace Simulator {
    partial class frmMain {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
			this.components = new System.ComponentModel.Container();
			this.statusStrip1 = new System.Windows.Forms.StatusStrip();
			this.tsLblStatus = new System.Windows.Forms.ToolStripStatusLabel();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.serialPortToolStripMenuItem = new System.Windows.Forms.ToolStripComboBox();
			this.connectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
			this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.pbRoom = new System.Windows.Forms.PictureBox();
			this.tim500 = new System.Windows.Forms.Timer(this.components);
			this.tim100 = new System.Windows.Forms.Timer(this.components);
			this.tim10 = new System.Windows.Forms.Timer(this.components);
			this.resetRoombaToCenterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.tim1000 = new System.Windows.Forms.Timer(this.components);
			this.statusStrip1.SuspendLayout();
			this.menuStrip1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.pbRoom)).BeginInit();
			this.SuspendLayout();
			// 
			// statusStrip1
			// 
			this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsLblStatus});
			this.statusStrip1.Location = new System.Drawing.Point(0, 754);
			this.statusStrip1.Name = "statusStrip1";
			this.statusStrip1.Size = new System.Drawing.Size(1542, 22);
			this.statusStrip1.TabIndex = 0;
			this.statusStrip1.Text = "statusStrip1";
			// 
			// tsLblStatus
			// 
			this.tsLblStatus.Name = "tsLblStatus";
			this.tsLblStatus.Size = new System.Drawing.Size(117, 17);
			this.tsLblStatus.Text = "Status: Disconnected";
			// 
			// menuStrip1
			// 
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.resetRoombaToCenterToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(1542, 24);
			this.menuStrip1.TabIndex = 1;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.serialPortToolStripMenuItem,
            this.connectToolStripMenuItem,
            this.toolStripMenuItem1,
            this.exitToolStripMenuItem});
			this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
			this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
			this.fileToolStripMenuItem.Text = "File";
			// 
			// serialPortToolStripMenuItem
			// 
			this.serialPortToolStripMenuItem.Name = "serialPortToolStripMenuItem";
			this.serialPortToolStripMenuItem.Size = new System.Drawing.Size(152, 23);
			this.serialPortToolStripMenuItem.Text = "Serial Port:";
			// 
			// connectToolStripMenuItem
			// 
			this.connectToolStripMenuItem.Name = "connectToolStripMenuItem";
			this.connectToolStripMenuItem.Size = new System.Drawing.Size(212, 22);
			this.connectToolStripMenuItem.Text = "&Connect";
			this.connectToolStripMenuItem.Click += new System.EventHandler(this.connectToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this.toolStripMenuItem1.Name = "toolStripMenuItem1";
			this.toolStripMenuItem1.Size = new System.Drawing.Size(209, 6);
			// 
			// exitToolStripMenuItem
			// 
			this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
			this.exitToolStripMenuItem.Size = new System.Drawing.Size(212, 22);
			this.exitToolStripMenuItem.Text = "&Exit";
			// 
			// pbRoom
			// 
			this.pbRoom.Dock = System.Windows.Forms.DockStyle.Fill;
			this.pbRoom.Location = new System.Drawing.Point(0, 24);
			this.pbRoom.Name = "pbRoom";
			this.pbRoom.Size = new System.Drawing.Size(1542, 730);
			this.pbRoom.TabIndex = 2;
			this.pbRoom.TabStop = false;
			// 
			// tim500
			// 
			this.tim500.Interval = 500;
			// 
			// tim100
			// 
			this.tim100.Enabled = true;
			this.tim100.Tick += new System.EventHandler(this.tim100_Tick);
			// 
			// tim10
			// 
			this.tim10.Enabled = true;
			this.tim10.Interval = 10;
			this.tim10.Tick += new System.EventHandler(this.tim10_Tick);
			// 
			// resetRoombaToCenterToolStripMenuItem
			// 
			this.resetRoombaToCenterToolStripMenuItem.Name = "resetRoombaToCenterToolStripMenuItem";
			this.resetRoombaToCenterToolStripMenuItem.Size = new System.Drawing.Size(145, 20);
			this.resetRoombaToCenterToolStripMenuItem.Text = "Reset Roomba to center";
			this.resetRoombaToCenterToolStripMenuItem.Click += new System.EventHandler(this.resetRoombaToCenterToolStripMenuItem_Click);
			// 
			// tim1000
			// 
			this.tim1000.Enabled = true;
			this.tim1000.Interval = 1000;
			this.tim1000.Tick += new System.EventHandler(this.tim1000_Tick);
			// 
			// frmMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1542, 776);
			this.Controls.Add(this.pbRoom);
			this.Controls.Add(this.statusStrip1);
			this.Controls.Add(this.menuStrip1);
			this.MainMenuStrip = this.menuStrip1;
			this.Name = "frmMain";
			this.Text = "Form1";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmMain_FormClosing);
			this.Load += new System.EventHandler(this.frmMain_Load);
			this.statusStrip1.ResumeLayout(false);
			this.statusStrip1.PerformLayout();
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.pbRoom)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel tsLblStatus;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripComboBox serialPortToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem connectToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.PictureBox pbRoom;
        private System.Windows.Forms.Timer tim500;
        private System.Windows.Forms.Timer tim100;
        private System.Windows.Forms.Timer tim10;
		private System.Windows.Forms.ToolStripMenuItem resetRoombaToCenterToolStripMenuItem;
		private System.Windows.Forms.Timer tim1000;
    }
}

