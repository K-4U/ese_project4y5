using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simulator {
    class sensor {
        private int packetId;
        private string friendlyName;
        private int dataCount;
        private byte[] dataBytes;
        
        public sensor(string name, int packetId, int dataCount){
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

    class sensorGroup {
        private int groupId;
        private int min;
        private int max;
        private int packetSize;

        public sensorGroup(int groupId, int min, int max, int packetSize) {
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
            for (int i = 0; i < (min-max); i++) {
                sensor cSensor = list.getSensor(i);
                cSensor.getValue().CopyTo(returnPacket, returnPacket.Length);
            }
            return returnPacket;
        }
    }

    class sensorList {
        private List<sensor> sList = new List<sensor>();
        private List<sensorGroup> gList = new List<sensorGroup>();


        public void Add(sensor sensorToAdd){
            sList.Add(sensorToAdd);
        }

        public void AddGroup(sensorGroup groupToAdd) {
            gList.Add(groupToAdd);
        }

        public sensor getSensor(int packetId) {
            sensor toReturn = new sensor("", 0, 0);
            for (int i = 0; i < sList.Count-1; i++) {
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

    class roomba {
        enum roombaModes {
            Off = 0x00,
            Passive,
            Safe,
            Full
        }

        private roombaModes currentMode = roombaModes.Off;
        private byte[] getSensor(int packetId);
        private sensorList sensors;

        public roomba() {
            this.sensors = new sensorList();
            //Init list of sensors:
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


        }

    }
}
