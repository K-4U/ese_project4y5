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
        roomba
    }

    public partial class frmMain : Form {
        private static serialServer serSock;
        static ManualResetEvent _quitEvent = new ManualResetEvent(false);

        static int command = 0;
        static int byteCount = 0;
        static int currentByteCount = 0;

        List<int> dataBytes = new List<int>();

        static void log(string x, logTags tag) {
            string lTag = "";
            if (tag == logTags.program) {
                lTag = "PROG";
            } else if (tag == logTags.serialServer) {
                lTag = "SERI";
            } else if (tag == logTags.serial) {
                lTag = "BYTE";
            } else if (tag == logTags.roomba) {
                lTag = "ROOM";
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
        }

        private void messageHandlerSocket(int bRead, int prevByte) {

            int[,] mainCommands = { {128,0}, {129,1}, {130,0}, {131,0}, {132,0}, {133,0}, {134,0}, {135,0}, {136,0}, {137,4}, {145,4}, {138,1}, {144,3}, {146,4}, {139,3}, {140,0} };
            bool isMainCommand = false;

            if (command == 0) {

                for (int i = 0; i < mainCommands.Length; i++) {

                    if (mainCommands[i, 0] == bRead) {

                        isMainCommand = true;
                        byteCount = mainCommands[i, 1];

                        if (byteCount == 0) {

                            switch (mainCommands[i, 0]) {
                                case 128: /* roomba.start */ break;
                                case 130: /* roomba.control */ break;
                                case 131: /* roomba.safe */ break;
                                case 132: /* roomba.full */ break;
                                case 133: /* roomba.power */ break;
                                case 134: /* roomba.spot */ break;
                                case 135: /* roomba.clean */ break;
                                case 136: /* roomba.max */ break;
                                case 140: /* roomba.song */ break;
                            }

                        } else {
                            command = mainCommands[i, 0];
                        }

                        break;
                    }
                }

                log(isMainCommand ? "true" : "false", logTags.serial);

            } else {

                currentByteCount++;
                dataBytes.Add(bRead);

                if (currentByteCount == byteCount) {

                    switch (command) {
                        // call function, pass int list dataBytes as argument.
                        case 129: /* roomba.baud 1 */ break;
                        case 137: /* roomba.drive 4 */ break;
                        case 145: /* roomba.drive wheels 4 */ break;
                        case 138: /* roomba.motors 1 */ break;
                        case 144: /* roomba.pwm motors 3 */ break;
                        case 146: /* roomba.drive pwm 4 */ break;
                        case 139: /* roomba.leds 3 */ break;
                    }

                    /* reset to prepare for new receive */
                    dataBytes.Clear();
                    command = 0;
                    byteCount = 0;
                    currentByteCount = 0;
                      
                }
            }
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
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
