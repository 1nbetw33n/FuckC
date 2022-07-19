//
// Created by 0x1nbetw33n on 25/04/22.
//

static int callCounter;

void counter(void){
    callCounter++;
}

int showCounter(){
    return callCounter;
}

