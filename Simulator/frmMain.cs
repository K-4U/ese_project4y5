using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Simulator {
    enum logTags {
        program = ConsoleColor.Green,
        serial,
        serialServer,
        roomba = ConsoleColor.Yellow
    }

    public partial class frmMain : Form {
        private static serialServer serSock;
        private static clsRoomba roomba;

        static void log(string x, logTags tag) {
            string lTag = "";
            if (tag == logTags.program) {
                lTag = "PROG";
            } else if (tag == logTags.serialServer) {
                lTag = "SERI";
            } else if (tag == logTags.serial) {
                lTag = "BYTE";
            } else if (tag == logTags.roomba) {
                lTag = "RMBA";
            }
            ConsoleColor oldColor = Console.ForegroundColor;
            Console.ForegroundColor = (ConsoleColor)tag;
            //Console.Write(String.Format("[{0}]\t", lTag));
            Console.WriteLine(String.Format("[{0}]\t{1}", lTag, x));
            Console.ForegroundColor = oldColor;

        }

        public frmMain() {
            InitializeComponent();
            //Load serial server:
            serSock = new serialServer();
            serSock.setLogFunction(log);

            serSock.setMessageHandler(messageHandlerSocket);


            roomba = new clsRoomba(log);
        }

        private void messageHandlerSocket(int bRead, int prevByte) {
        }

        private void frmMain_Load(object sender, EventArgs e) {
            //Find the serial port names
            foreach (COMPortInfo comPort in COMPortInfo.GetCOMPortsInfo()) {
                serialPortToolStripMenuItem.Items.Add(comPort.Description);
            }
        }

        private void frmMain_FormClosing(object sender, FormClosingEventArgs e) {
            if (serSock.isConnected()) {
                serSock.disconnect();
            }
        }

        private void connectToolStripMenuItem_Click(object sender, EventArgs e) {
            String selectedPort = "";
            foreach (COMPortInfo comPort in COMPortInfo.GetCOMPortsInfo()) {
                if (comPort.Description == serialPortToolStripMenuItem.SelectedItem.ToString()) {
                    selectedPort = comPort.Name;
                }
            }

            serSock.init(selectedPort, Properties.Settings.Default.baudRate);

            try {
                serSock.connect();
            } catch (serialException exc) {
                log(String.Format("ERROR: {0}\r\nStack{1}", exc.Message, exc.StackTrace), logTags.serialServer);
            }
        }
    }
}
