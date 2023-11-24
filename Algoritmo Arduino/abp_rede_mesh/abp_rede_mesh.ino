#include "painlessMesh.h"
#include <Arduino_JSON.h>
#include "SPIFFS.h"
#include "FS.h"

#define MESH_PREFIX   "MeshNetwork"
#define MESH_PASSWORD "MeshPassword"
#define MESH_PORT     5555

int node_number = 1; 

Scheduler userScheduler; // to control your personal task
painlessMesh  mesh;


void sendMessage() ; 


Task taskSendMessage( TASK_SECOND * 5 , TASK_FOREVER, &sendMessage );

bool get_parking_status() {
  float  dist_cm = 0;
  bool parking_status = 0;

  dist_cm = 50;

  if(dist_cm <= 100){ //Ocupado
    parking_status = 1;
  }
  else{ //Livre
    parking_status = 0;
  }
  return parking_status;
}

String getReadings () {
  String readings;
  
  JSONVar jsonStruct;
  jsonStruct["nodeNumber"] = node_number;
  //jsonStruct["nodeId"] = mesh.getNodeId();
  jsonStruct["state"] = get_parking_status();
  readings = JSON.stringify(jsonStruct);
  return readings;
}

void sendMessage() {
  String msg = getReadings();

  if (node_number != 1){
    mesh.sendBroadcast( msg );
  }
  else {
    Serial.printf(msg.c_str());
  }
}

// Needed for painless library
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf(msg.c_str());
  Serial.printf("\n");
  
  JSONVar myObject = JSON.parse(msg.c_str());
  int node = myObject["nodeNumber"];
  //String nodeId = myObject["nodeId"];
  bool parking_status = myObject["state"];

  /*
  Serial.print("Node: ");
  Serial.println(node);
  Serial.print("ID do Node: ");
  Serial.println(nodeId);
  Serial.print("Status da vaga: ");
  Serial.println(parking_status);
  */
}

void newConnectionCallback(uint32_t nodeId) {
    Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
    Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}

void setup() {
  Serial.begin(115200);
  SPIFFS.begin();

  mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages

  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  userScheduler.addTask( taskSendMessage );
  taskSendMessage.enable();
}

void loop() {
  // it will run the user scheduler as well
  mesh.update();
}
