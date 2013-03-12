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

        static byte command = 0;
        static byte byteCount = 0;
        List<byte> dataBytes = new List<byte>();

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

        void clearRegisters() {
            // call song command, then clear regs.
            byte[] storeTemp = { };
            if (command == 140) {
                storeTemp[0] = dataBytes[0];
                storeTemp[1] = dataBytes[1];
                dataBytes.RemoveRange(0, 1);
                roomba.song(storeTemp[0], storeTemp[1], dataBytes.ToArray());
            }
            byteCount = 0;
            dataBytes.Clear();
        }

        private void messageHandlerSocket(byte bRead, byte prevByte) {


            byte[,] mainCommands = { {128,0}, {129,1}, {130,0}, {131,0}, {132,0}, {133,0}, {134,0}, {135,0}, {136,0}, {137,4}, {145,4}, {138,1}, {144,3}, {146,4}, {139,3}, {140,0} };
            bool isMainCommand = false;

            // if no current command, or command of undefined length
            if (command == 0 || command == 140) {

                for (int i = 0; i < mainCommands.Length; i++) {

                    if (mainCommands[i, 0] == bRead) {

                        isMainCommand = true;
                        clearRegisters();
                        byteCount = mainCommands[i, 1];

                        if (byteCount == 0 && command != 140) {

                            switch (mainCommands[i, 0]) {
                                case 128: roomba.start(); break;
                                case 130:
                                case 131: roomba.safe(); break;
                                case 132: roomba.full(); break;
                                case 133: roomba.power(); break;
                                case 134: roomba.spot(); break;
                                case 135: roomba.clean(); break;
                                case 136: roomba.max(); break;
                            }

                        } else {
                            command = mainCommands[i, 0];
                        }

                        break;
                    }
                }

                log(isMainCommand ? "true" : "false", logTags.serial);

            } else {

                dataBytes.Add(bRead);

                if (dataBytes.Count == byteCount && command != 140) {

                    switch (command) {

                        /*
                         *  call functions, pass int list dataBytes as argument.
                         */

                        case 137:   roomba.drive(dataBytes[0], dataBytes[1], dataBytes[2], dataBytes[3]);
                                    break;
                        case 145:   roomba.driveDirect(dataBytes[0], dataBytes[1], dataBytes[2], dataBytes[3]);
                                    break;
                        case 138:   roomba.motors(dataBytes[0]); 
                                    break;
                        case 144:   roomba.pwmMotors(dataBytes[0], dataBytes[1], dataBytes[2]);
                                    break;
                        case 146:   roomba.drivePwm(dataBytes[0], dataBytes[1], dataBytes[2], dataBytes[3]);
                                    break;
                        case 139:   roomba.leds(dataBytes[0], dataBytes[1], dataBytes[2]);
                                    break;

                        case 129: // baud is not implemented
                        default: break;
                    }

                    /* reset to prepare for new receive */
                    command = 0;
                    clearRegisters();
                      
                }
            }
        }

        private void frmMain_Load(object sender, EventArgs e){
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
