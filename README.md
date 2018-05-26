float start[3];
float sps2[3];
float sps3[3];
float mystate[12];
float target[3];
int step;
float item1[3];
float item2[3];
float zinfo[4];
void init(){
	api.getMyZRState(mystate);
	start[0] = mystate[0];
	start[1] = mystate[1];
	start[2] = mystate[2];
	
	item1[0]=-0.5;
	item1[1]=0.354;
	item1[2]=0;
	
	sps2[0] = -0.70;
	sps2[1] = 0.70;
	sps2[2] = 0.0;
	
	sps3[0] = 0.70;
	sps3[1] = 0.70;
	sps3[2] = 0.0;
	
	item2[0]=0;
	item2[1]=1;
	item2[2]=0;
	
	step = 0;
	
	game.dropSPS();
	api.setPositionTarget(sps2);
}

void loop(){//void loop starts
	api.getMyZRState(mystate);
	game.getZone(zinfo);
	if (step == 0){
	    target[0] = -0.7;
	
	if (mystate[0] > target[0]){
	    api.setPositionTarget(sps2);
	}
	else{
	    game.dropSPS();
	    step++;
	}  
}
	else if (step == 1){
	    target[0] = 0.7;
	
	if (mystate[0] < target[0]){
	    api.setPositionTarget(sps3);
	}
	else{
	    game.dropSPS();
	    step++;
	} }
else if(step==2){
    api.setPositionTarget(item1);
    api.setAttitudeTarget(item2);
    game.dockItem();
} if(game.hasItemBeenPickedUp(4)==true){step++;} 
 //inside step 2
if(step==3){
    api.setVelocityTarget(zinfo);}
    
}//end of void loop

