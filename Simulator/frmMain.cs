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
        serial = ConsoleColor.Blue,
        serialServer,
        roomba = ConsoleColor.Yellow,
        error = ConsoleColor.Red
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
            command = 0;
            byteCount = 0;
            dataBytes.Clear();
        }

        private void messageHandlerSocket(byte bRead, byte prevByte) {

            byte[,] mainCommands = { {128,0}, {129,1}, {130,0}, {131,0}, {132,0}, {133,0}, {134,0}, {135,0}, {136,0}, {137,4}, {145,4}, {138,1}, {144,3}, {146,4}, {139,3}, {140,2} };
            byte[] storeTemp = {0,0};

            try {

                // decide: is this a mainCommand or a databyte
                if (command == 0) {

                    for (int i = 0; i < mainCommands.Length / 2; i++) {
                        if (mainCommands[i, 0] == bRead) {
                            command = mainCommands[i, 0];
                            byteCount = mainCommands[i, 1];
                            log(String.Format("Main command received: {0}", bRead), logTags.serial);
                            break; // no need to keep looping
                        }
                    }
                } else {
                    dataBytes.Add(bRead);
                    log(String.Format("Databyte received: {0}", bRead), logTags.serial);

                    // dynamic byte count
                    if (command == 140 && dataBytes.Count == 2) {
                        byteCount = (byte)((dataBytes[1]*2) + (byte)2);
                    }

                }

                if (dataBytes.Count == byteCount) {

                    switch (command) {
                        case 128: roomba.start(); break;
                        case 130: // catch this one, set to safe.
                        case 131: roomba.safe(); break;
                        case 132: roomba.full(); break;
                        case 133: roomba.power(); break;
                        case 134: roomba.spot(); break;
                        case 135: roomba.clean(); break;
                        case 136: roomba.max(); break;
                        case 137: roomba.drive(dataBytes[0], dataBytes[1], dataBytes[2], dataBytes[3]); break;
                        case 145: roomba.driveDirect(dataBytes[0], dataBytes[1], dataBytes[2], dataBytes[3]); break;
                        case 138: roomba.motors(dataBytes[0]); break;
                        case 144: roomba.pwmMotors(dataBytes[0], dataBytes[1], dataBytes[2]); break;
                        case 146: roomba.drivePwm(dataBytes[0], dataBytes[1], dataBytes[2], dataBytes[3]); break;
                        case 139: roomba.leds(dataBytes[0], dataBytes[1], dataBytes[2]); break;
                        case 140: storeTemp[0] = dataBytes[0];
                                  storeTemp[1] = dataBytes[1];
                                  dataBytes.RemoveRange(0, 1);
                                  roomba.song(storeTemp[0], storeTemp[1], dataBytes.ToArray());
                                  break;
                        case 129: // baud is not implemented
                        default: break;
                    }


                    clearRegisters();
                }

            } catch (clsRoomba.notInCorrectMode excep) {
                log(String.Format("Not in correct mode when calling function {0}", excep.TargetSite.Name), logTags.program);


                clearRegisters();
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
