using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulator {
    class clsRoomba {
        #region Errors
        [Serializable]
        public class notInCorrectMode : Exception {
            public notInCorrectMode() : base() { }
        }
        #endregion

        #region Sensors
        private class sensor {
            private int packetId;
            private string friendlyName;
            private int dataCount;
            private byte[] dataBytes;

            public sensor(string name, int packetId, int dataCount) {
                this.friendlyName = name;
                this.dataBytes = new byte[dataCount];
                this.packetId = packetId;
                this.dataCount = dataCount;
            }

            public int getPacketId() {
                return this.packetId;
            }

            public byte[] getValue() {
                return this.dataBytes;
            }
        }

        private class sensorGroup {
            private int groupId;
            private int min;
            private int max;
            private int packetSize;

            public sensorGroup(int groupId, int packetSize, int min, int max) {
                this.groupId = groupId;
                this.min = min;
                this.max = max;
                this.packetSize = packetSize;
            }

            public int getGroupId() {
                return this.groupId;
            }

            public byte[] getGroup(sensorList list) {
                byte[] returnPacket = new byte[this.packetSize];
                for (int i = 0; i < (min - max); i++) {
                    sensor cSensor = list.getSensor(i);
                    cSensor.getValue().CopyTo(returnPacket, returnPacket.Length);
                }
                return returnPacket;
            }
        }

        private class sensorList {
            private List<sensor> sList = new List<sensor>();
            private List<sensorGroup> gList = new List<sensorGroup>();


            public void Add(sensor sensorToAdd) {
                sList.Add(sensorToAdd);
            }

            public void AddGroup(sensorGroup groupToAdd) {
                gList.Add(groupToAdd);
            }

            public sensor getSensor(int packetId) {
                sensor toReturn = new sensor("", 0, 0);
                for (int i = 0; i < sList.Count - 1; i++) {
                    if (sList[i].getPacketId() == packetId) {
                        toReturn = sList[i];
                        break;
                    }
                }
                return toReturn;
            }

            public byte[] getSensorValue(int packetId) {
                sensor toReturn = this.getSensor(packetId);
                return toReturn.getValue();
            }

            public byte[] getGroup(int groupId) {
                sensorGroup currentGroup = new sensorGroup(0, 0, 0, 0);
                foreach (sensorGroup group in gList) {
                    if (group.getGroupId() == groupId) {
                        currentGroup = group;
                        break;
                    }
                }
                return currentGroup.getGroup(this);
            }
        }

        #endregion 

        #region Log
        public delegate void logDelegate(String x, logTags tag);
        private logDelegate log = new logDelegate(logDummy);
        private static void logDummy(string x, logTags tag) { }
        private const logTags TAG = logTags.roomba;
        #endregion 

        #region Variables
        private roombaModes currentMode = roombaModes.Off;
        private sensorList sensors;
        private stDrivingState drivingState;

        #region Enums
        enum roombaModes {
            Off = 0x00,
            Passive,
            Safe,
            Full
        }
        enum direction {
            defaultDir = 0x00,
            opposite
        }
        #endregion 
        #region Structs
        struct stDrivingState {
            public bool isDriving;
            public int velocity;
            public int radius;
            public int rightSpeed;
            public int leftSpeed;
            public int rightPWM;
            public int leftPWM;
        }
        struct stMotors {
            public bool mainBrush;
            public direction 
            public bool vacuum;
            public bool sideBrush;

        }
        #endregion
        #endregion

        #region Private
        private bool checkMode(params roombaModes[] paramList) {
            bool ret = false;
            foreach (roombaModes o in paramList) {
                ret = (this.currentMode == o);
                if (ret == true) {
                    break;
                }
            }
            return ret;
        }
        #endregion

        public clsRoomba(logDelegate logFunc) {
            log += new logDelegate(logFunc);

            log("Initializing", TAG);
            this.drivingState = new stDrivingState();
            this.sensors = new sensorList();
            //Init list of sensors:
            log("Adding sensors", TAG);
            sensors.Add(new sensor("Bump and wheel drops", 7, 1));
            sensors.Add(new sensor("Wall", 8, 1));
            sensors.Add(new sensor("Cliff Left", 9, 1));
            sensors.Add(new sensor("Cliff Front Left", 10, 1));
            sensors.Add(new sensor("Cliff Front Right", 11, 1));
            sensors.Add(new sensor("Cliff Right", 12, 1));
            sensors.Add(new sensor("Virtual wall", 13, 1));
            sensors.Add(new sensor("Wheel overcurrents", 14, 1));
            sensors.Add(new sensor("Dirt Detect", 15, 1));
            sensors.Add(new sensor("Unused Byte", 16, 2));
            sensors.Add(new sensor("Infrared Character Omni", 17, 1));
            sensors.Add(new sensor("Infrared Character Left", 52, 1));
            sensors.Add(new sensor("Infrared Character Right", 53, 1));
            sensors.Add(new sensor("Buttons", 18, 1));
            sensors.Add(new sensor("Distance", 19, 2));
            sensors.Add(new sensor("Angle", 20, 2));
            sensors.Add(new sensor("Charging State", 21, 1));
            sensors.Add(new sensor("Voltage", 22, 2));
            sensors.Add(new sensor("Current", 23, 2));
            sensors.Add(new sensor("Temperature", 24, 1));
            sensors.Add(new sensor("Battery Charge", 25, 2));
            sensors.Add(new sensor("Battery Capacity", 26, 2));
            sensors.Add(new sensor("Wall signal", 27, 2));
            sensors.Add(new sensor("Cliff Left Signal", 28, 2));
            sensors.Add(new sensor("Cliff Front Left Signal", 29, 2));
            sensors.Add(new sensor("Cliff Front Right Signal", 30, 2));
            sensors.Add(new sensor("Cliff Right Signal", 31, 2));
            sensors.Add(new sensor("Unused", 32, 3));
            sensors.Add(new sensor("Unused", 33, 3));
            sensors.Add(new sensor("Charging Sources Available", 43, 1));
            sensors.Add(new sensor("OI Mode", 35, 1));
            sensors.Add(new sensor("Song Number", 36, 1));
            sensors.Add(new sensor("Song Playing", 37, 1));
            sensors.Add(new sensor("Number of Stream Packets", 38, 1));
            sensors.Add(new sensor("Requested Velocity", 39, 2));
            sensors.Add(new sensor("Requested Radius", 40, 2));
            sensors.Add(new sensor("Requested Right Velocity", 41, 2));
            sensors.Add(new sensor("Requested Left Velocity", 42, 2));
            sensors.Add(new sensor("Right Encoder Counts", 43, 2));
            sensors.Add(new sensor("Left Encode Counts", 44, 2));
            sensors.Add(new sensor("Light Bumper", 45, 1));
            sensors.Add(new sensor("Light Bump Left Signal", 46, 2));
            sensors.Add(new sensor("Light Bump Front Left Signal", 47, 2));
            sensors.Add(new sensor("Light Bump Center Left Signal", 48, 2));
            sensors.Add(new sensor("Light Bump Center Right Signal", 49, 2));
            sensors.Add(new sensor("Light Bump Front Right Signal", 50, 2));
            sensors.Add(new sensor("Light Bump Right Signal", 51, 2));
            sensors.Add(new sensor("Left Motor Current", 54, 2));
            sensors.Add(new sensor("Right Motor Current", 55, 2));
            sensors.Add(new sensor("Main Brush Motor Current", 56, 2));
            sensors.Add(new sensor("Side Brush Motor Current", 57, 2));
            sensors.Add(new sensor("Stasis", 58, 1));

            log("Done adding sensors", TAG);
            log("Adding sensor groups", TAG);

            sensors.AddGroup(new sensorGroup(0, 26, 6, 26));
            sensors.AddGroup(new sensorGroup(1, 10, 7, 16));
            sensors.AddGroup(new sensorGroup(2, 6, 17, 20));
            sensors.AddGroup(new sensorGroup(3, 10, 21, 26));
            sensors.AddGroup(new sensorGroup(4, 14, 27, 34));
            sensors.AddGroup(new sensorGroup(5, 12, 35, 42));
            sensors.AddGroup(new sensorGroup(6, 52, 7, 41));
            sensors.AddGroup(new sensorGroup(100, 80, 7, 58));
            sensors.AddGroup(new sensorGroup(101, 28, 43, 58));
            sensors.AddGroup(new sensorGroup(106, 12, 46, 51));
            sensors.AddGroup(new sensorGroup(107, 9, 54, 58));

            log("Done adding sensor groups", TAG);

            log("Initialized", TAG);
        }

       

        public void start() {
            if (this.currentMode == roombaModes.Off) {
                Console.Beep();
            }
            this.currentMode = roombaModes.Passive;
            log("Switching mode to passive", TAG);
        }
        public void safe() {
            this.currentMode = roombaModes.Safe;
            log("Switching mode to safe", TAG);
        }
        public void full() {
            this.currentMode = roombaModes.Full;
            log("Switching mode to full", TAG);
        }

        public void power() {
            //Powers down the Roomba
            this.currentMode = roombaModes.Passive;
            log("Powering down", TAG);
        }

        public void spot() {
            if (this.checkMode(roombaModes.Full, roombaModes.Safe, roombaModes.Passive)) {
                log("Starting spot mode", TAG);
                this.currentMode = roombaModes.Passive;
            } else {
                throw new notInCorrectMode();
            }
        }

        public void clean() {
            if (this.checkMode(roombaModes.Full, roombaModes.Safe, roombaModes.Passive)) {
                log("Starting clean mode", TAG);
                this.currentMode = roombaModes.Passive;
            } else {
                throw new notInCorrectMode();
            }
        }

        public void max() {
            if (this.checkMode(roombaModes.Full, roombaModes.Safe, roombaModes.Passive)) {
                log("Starting max clean mode", TAG);
                this.currentMode = roombaModes.Passive;
            } else {
                throw new notInCorrectMode();
            }
        }

        public void song(int songNumber, int noteCount, params byte[] arguments) {
            if (this.checkMode(roombaModes.Full, roombaModes.Safe, roombaModes.Passive)) {
                log(String.Format("Storing a song in {0}",songNumber), TAG);
            } else {
                throw new notInCorrectMode();
            }
        }

        public void drive(byte velocHigh, byte velocLow, byte radiusHigh, byte radiusLow) {
            if (this.checkMode(roombaModes.Safe, roombaModes.Full)) {
                this.drivingState.velocity = (velocHigh << 8) | velocLow;
                this.drivingState.radius = (radiusHigh << 8) | radiusLow;
                this.drivingState.leftPWM = 0;
                this.drivingState.rightPWM = 0;
                this.drivingState.leftSpeed = 0;
                this.drivingState.rightSpeed = 0;
                if (this.drivingState.velocity == 0) {
                    this.drivingState.isDriving = false;
                    log("Stopped driving", TAG);
                } else {
                    this.drivingState.isDriving = true;
                    log(String.Format("Driving @ {0}mm/s in a radius of {1} degrees", this.drivingState.velocity,this.drivingState.radius),TAG);
                }
            } else {
                throw new notInCorrectMode();
            }
        }

        public void driveDirect(byte velocRightHigh, byte velocRightLow, byte velocLeftHigh, byte velocLeftLow) {
            if (this.checkMode(roombaModes.Safe, roombaModes.Full)) {
                this.drivingState.velocity = 0;
                this.drivingState.radius = 0;
                this.drivingState.leftPWM = 0;
                this.drivingState.rightPWM = 0;
                this.drivingState.leftSpeed = (velocLeftHigh << 8) | velocLeftLow;
                this.drivingState.rightSpeed = (velocRightHigh << 8) | velocRightLow;
                if (this.drivingState.leftSpeed == 0 && this.drivingState.rightSpeed == 0) {
                    this.drivingState.isDriving = false;
                    log("Stopped driving", TAG);
                } else {
                    this.drivingState.isDriving = true;
                    log(String.Format("Driving @ {0}mm/s left, {1}mm/s right", this.drivingState.leftSpeed, this.drivingState.rightSpeed), TAG);
                }
            } else {
                throw new notInCorrectMode();
            }
        }

        public void drivePWM(byte pwmRightHigh, byte pwmRightLow, byte pwmLeftHigh, byte pwmLeftLow) {
            if (this.checkMode(roombaModes.Safe, roombaModes.Full)) {
                this.drivingState.velocity = 0;
                this.drivingState.radius = 0;
                this.drivingState.leftSpeed = 0;
                this.drivingState.rightSpeed = 0;
                this.drivingState.leftPWM = (pwmLeftHigh << 8) | pwmLeftLow;
                this.drivingState.rightPWM = (pwmRightHigh << 8) | pwmRightLow;
                if (this.drivingState.leftPWM == 0 && this.drivingState.rightPWM == 0) {
                    this.drivingState.isDriving = false;
                    log("Stopped driving", TAG);
                } else {
                    this.drivingState.isDriving = true;
                    log(String.Format("Driving @ {0} left, {1} right", this.drivingState.leftPWM, this.drivingState.rightPWM), TAG);
                }
            } else {
                throw new notInCorrectMode();
            }
        }

        public void motors(byte newValue) {
            if (this.checkMode(roombaModes.Safe, roombaModes.Full)) {

            } else {
                throw new notInCorrectMode();
            }
        }

        
    }
}
