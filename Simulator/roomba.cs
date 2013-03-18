﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
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

            virtual public byte[] getValue() {
                return this.dataBytes;
            }

            public void setValue(int newValue) {
                if (this.dataCount == 2) {
                    this.dataBytes[0] = (byte)(newValue >> 8);
                    this.dataBytes[1] = (byte)(newValue & 0xFF);
                }else{
                    this.dataBytes[0] = (byte)(newValue & 0xFF);
                }
            }
        }

        private class resetSensor : sensor {

            public resetSensor(string name, int packetId, int dataCount) : base(name, packetId,dataCount){
            }
            public override byte[] getValue() {
                byte[] t = (byte[])base.getValue().Clone();
                base.setValue(0);
                return t;
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

            public void setSensorValue(int packetId, int newValue) {
                for (int i = 0; i < sList.Count - 1; i++) {
                    if (sList[i].getPacketId() == packetId) {
                        sList[i].setValue(newValue);
                        break;
                    }
                }
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

        #region Callbacks
        public delegate void sendDelegate(byte[] bytes);
        private sendDelegate send = new sendDelegate(sendDummy);
        private static void sendDummy(byte[] bytes) { }
        #endregion

        #region Variables
        private eRoombaModes currentMode = eRoombaModes.Off;
        private sensorList sensors;
        private stDrivingState drivingState;
        private stMotors motorState;
        private stLeds ledState;
        private stStream stream;
        private Thread streamThread;
        private Thread drivingThread;

        #region Enums
        enum eRoombaModes {
            Off = 0x00,
            Passive,
            Safe,
            Full
        }
        enum eDirection {
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
            public int mainBrushPwm;
            public eDirection mainBrushDirection;
            public bool vacuum;
            public int vacuumPwm;
            public bool sideBrush;
            public int sideBrushPwm;
            public eDirection sideBrushDirection;
        }

        struct stLeds {
            public bool checkRobot;
            public bool dock;
            public bool spot;
            public bool debris;
            public byte ledColor;
            public byte ledIntensity;
        }

        struct stStream {
            public bool doStream;
            public int packetCount;
            public List<int> packets;
        }
        #endregion
        #endregion

        #region Private
        private bool checkMode(params eRoombaModes[] paramList) {
            bool ret = false;
            foreach (eRoombaModes o in paramList) {
                ret = (this.currentMode == o);
                if (ret == true) {
                    break;
                }
            }
            return ret;
        }

        private void streamFunc() {
            while (true) {
                if (this.stream.doStream) {
                    //Build packet:
                    List<byte> btoSend = new List<byte>();
                    btoSend.Add(19);
                    int byteCount = 0;
                    btoSend.Add(5);
                    foreach (int packetId in this.stream.packets) {
                        byteCount++;
                        btoSend.Add((byte)packetId);
                        byte[] bToAdd = this.sensors.getSensorValue(packetId);
                        foreach (byte data in bToAdd) {
                            byteCount++;
                            btoSend.Add(data);
                        }
                    }
                    //Fix length
                    btoSend[1] = (byte)byteCount;

                    this.send(btoSend.ToArray());
                    
                }
                Thread.Sleep(1000);
            }
        }

        private void motorThreadFunc() {
            while (true) {
                if (this.drivingState.isDriving) {
                    int avg = (this.drivingState.leftSpeed + this.drivingState.rightSpeed) / 2;
                    byte[] sValue = this.sensors.getSensorValue(19);
                    avg += (sValue[0] << 8) | (sValue[1]);

                    this.sensors.setSensorValue(19, avg);
                }
                Thread.Sleep(1000);
            }
        }
        #endregion

        public clsRoomba(logDelegate logFunc, sendDelegate sendFunc) {
            log += new logDelegate(logFunc);
            this.send += new sendDelegate(sendFunc);

            log("Initializing", TAG);
            this.drivingState = new stDrivingState();
            this.sensors = new sensorList();
            this.motorState = new stMotors();
            this.ledState = new stLeds();
            this.stream = new stStream();
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
            sensors.Add(new resetSensor("Distance", 19, 2));
            sensors.Add(new resetSensor("Angle", 20, 2));
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
            if (this.currentMode == eRoombaModes.Off) {
                Console.Beep();
            }
            this.currentMode = eRoombaModes.Passive;
            log("Switching mode to passive", TAG);
        }
        public void safe() {
            if (this.currentMode != eRoombaModes.Off) {
                this.currentMode = eRoombaModes.Safe;
                log("Switching mode to safe", TAG);
            } else {
                throw new notInCorrectMode();
            }
        }
        public void full() {
            if (this.currentMode != eRoombaModes.Off) {
                this.currentMode = eRoombaModes.Full;
                log("Switching mode to full", TAG);
            } else {
                throw new notInCorrectMode();
            }
        }

        public void power() {
            //Powers down the Roomba
            this.currentMode = eRoombaModes.Passive;
            log("Powering down", TAG);
        }

        public void spot() {
            if (this.checkMode(eRoombaModes.Full, eRoombaModes.Safe, eRoombaModes.Passive)) {
                log("Starting spot mode", TAG);
                this.currentMode = eRoombaModes.Passive;
            } else {
                throw new notInCorrectMode();
            }
        }

        public void clean() {
            if (this.checkMode(eRoombaModes.Full, eRoombaModes.Safe, eRoombaModes.Passive)) {
                log("Starting clean mode", TAG);
                this.currentMode = eRoombaModes.Passive;
            } else {
                throw new notInCorrectMode();
            }
        }

        public void max() {
            if (this.checkMode(eRoombaModes.Full, eRoombaModes.Safe, eRoombaModes.Passive)) {
                log("Starting max clean mode", TAG);
                this.currentMode = eRoombaModes.Passive;
            } else {
                throw new notInCorrectMode();
            }
        }

        public void song(byte songNumber, byte noteCount, params byte[] arguments) {
            if (this.checkMode(eRoombaModes.Full, eRoombaModes.Safe, eRoombaModes.Passive)) {
                log(String.Format("Storing a song in {0}", songNumber), TAG);
            } else {
                throw new notInCorrectMode();
            }
        }

        public void startStream(byte number, params byte[] packets){
            if (this.checkMode(eRoombaModes.Passive, eRoombaModes.Safe, eRoombaModes.Full)){
                this.stream.doStream = true;
                this.stream.packetCount = number;
                this.stream.packets = new List<int>();
                log(String.Format("Starting a stream of {0} packets:", number), TAG);
                foreach (byte packet in packets) {
                    this.stream.packets.Add(packet);
                    log(String.Format("- {0}", packet), TAG);
                }
                this.streamThread = new Thread(streamFunc);
                this.streamThread.Start();
                
            } else {
                throw new notInCorrectMode();
            }
        }

        public void pauseResumeStream(byte newState) {
            if (this.checkMode(eRoombaModes.Passive, eRoombaModes.Safe, eRoombaModes.Full)) {
                this.stream.doStream = (newState == 1);
            } else {
                throw new notInCorrectMode();
            }
        }

        public void drive(byte velocHigh, byte velocLow, byte radiusHigh, byte radiusLow) {
            if (this.checkMode(eRoombaModes.Safe, eRoombaModes.Full)) {
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
            if (this.checkMode(eRoombaModes.Safe, eRoombaModes.Full)) {
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
                    this.drivingThread = new Thread(motorThreadFunc);
                    this.drivingThread.Start();
                }
            } else {
                throw new notInCorrectMode();
            }
        }

        public void drivePwm(byte pwmRightHigh, byte pwmRightLow, byte pwmLeftHigh, byte pwmLeftLow) {
            if (this.checkMode(eRoombaModes.Safe, eRoombaModes.Full)) {
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

        private void printMotorState() {
            string logString = String.Format("Motor state:\r\n\tMain brush state:\t{0}\r\n\tMain brush direction:\t{1}\r\n\tMain brush pwm:\t\t{2}", (this.motorState.mainBrush ? "On" : "Off"), (this.motorState.mainBrushDirection == eDirection.defaultDir ? "Default" : "Opposite"), this.motorState.mainBrushPwm);
            logString += String.Format("\r\n\tSide brush state:\t{0}\r\n\tSide brush direction:\t{1}\r\n\tSide brush pwm:\t\t{2}", (this.motorState.sideBrush ? "On" : "Off"), (this.motorState.sideBrushDirection == eDirection.defaultDir ? "Default" : "Opposite"), this.motorState.sideBrushPwm);
            logString += String.Format("\r\n\tVacuum state:\t\t{0}\r\n\tVacuum pwm:\t\t{1}", (this.motorState.vacuum ? "On" : "Off"), this.motorState.vacuumPwm);
            log(logString, logTags.roomba);
        }

        public void motors(byte newValue) {
            if (this.checkMode(eRoombaModes.Safe, eRoombaModes.Full)) {
                this.motorState.mainBrushDirection = ((newValue & (1 << 4)) != 0 ? eDirection.opposite : eDirection.defaultDir);
                this.motorState.sideBrushDirection = ((newValue & (1 << 3)) != 0 ? eDirection.opposite : eDirection.defaultDir);
                this.motorState.mainBrush = ((newValue & (1 << 2)) != 0);
                this.motorState.vacuum = ((newValue & (1 << 1)) != 0);
                this.motorState.sideBrush = ((newValue & (1 << 0)) != 0);


                if (this.motorState.mainBrush == true) {
                    this.motorState.mainBrushPwm = (this.motorState.mainBrushDirection == eDirection.defaultDir ? 128 : -128);
                } else {
                    this.motorState.mainBrushPwm = 0;
                }
                if (this.motorState.sideBrush == true) {
                    this.motorState.sideBrushPwm = (this.motorState.sideBrushDirection == eDirection.defaultDir ? 128 : -128);
                } else {
                    this.motorState.sideBrushPwm = 0;
                }
                if(this.motorState.vacuum == true){
                    this.motorState.vacuumPwm = 128;
                }else{
                    this.motorState.vacuumPwm = 0;
                }

                this.printMotorState();
            } else {
                throw new notInCorrectMode();
            }
        }

        public void pwmMotors(byte mainBrushPwm, byte sideBrushPwm, byte vacuumPwm) {
            if(this.checkMode(eRoombaModes.Safe, eRoombaModes.Full)){
                this.motorState.mainBrushPwm = mainBrushPwm;
                this.motorState.sideBrushPwm = sideBrushPwm;
                this.motorState.vacuumPwm = vacuumPwm;

                if(this.motorState.mainBrushPwm == 0){
                    this.motorState.mainBrush = false;
                }else if(this.motorState.mainBrushPwm < 0){
                    this.motorState.mainBrushDirection = eDirection.opposite;
                    this.motorState.mainBrush = true;
                }else if(this.motorState.mainBrushPwm > 0){
                    this.motorState.mainBrushDirection = eDirection.defaultDir;
                    this.motorState.mainBrush = true;
                }

                if(this.motorState.sideBrushPwm == 0){
                    this.motorState.sideBrush = false;
                }else if(this.motorState.sideBrushPwm < 0){
                    this.motorState.sideBrushDirection = eDirection.opposite;
                    this.motorState.sideBrush = true;
                }else if(this.motorState.sideBrushPwm > 0){
                    this.motorState.sideBrushDirection = eDirection.defaultDir;
                    this.motorState.sideBrush = true;
                }
                this.printMotorState();
            }else{
                throw new notInCorrectMode();
            }
        }

        private void printLeds() {
            string logStr = String.Format("LED State: \r\n\t\tCheck Robot:\t{0}", (this.ledState.checkRobot == true ? "On" : "Off"));
            logStr += String.Format("\r\n\t\tDock:\t\t{0}", (this.ledState.dock == true ? "On" : "Off"));
            logStr += String.Format("\r\n\t\tSpot:\t\t{0}", (this.ledState.spot == true ? "On" : "Off"));
            logStr += String.Format("\r\n\t\tDebris:\t\t{0}", (this.ledState.debris == true ? "On" : "Off"));
            logStr += String.Format("\r\n\t\tColor pwm:\t{0}", this.ledState.ledColor);
            logStr += String.Format("\r\n\t\tIntensity:\t{0}", this.ledState.ledIntensity);
        }

        public void leds(byte ledBits, byte cleanPowerColor, byte cleanPowerIntensity) {
            if (this.checkMode(eRoombaModes.Safe, eRoombaModes.Full)) {
                this.ledState.checkRobot = ((ledBits & (1 << 3)) != 0);
                this.ledState.dock = ((ledBits & (1 << 2)) != 0);
                this.ledState.spot = ((ledBits & (1 << 1)) != 0);
                this.ledState.debris = ((ledBits & (1 << 0)) != 0);
                this.ledState.ledColor = cleanPowerColor;
                this.ledState.ledIntensity = cleanPowerIntensity;

                this.printLeds();
            } else {
                throw new notInCorrectMode();
            }
        }

        
        
    }
}
