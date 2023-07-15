#include <stdio.h>

struct vehicle{
    int wheel;
    int door;
    int engine;
    int speed;
    void (*drive)(struct vehicle *vc,char *s);
    void (*acclerate)(struct vehicle *vc,int speed);
    void (*brake)(struct vehicle *vc,int speed);
};

struct evehicle{
    struct vehicle vc;
    void (*charge)(struct evehicle *evc);
    int battery;
};

void ecar_charge(struct evehicle *evc){
    evc->battery=100;
}

void ecar_acclrate(struct vehicle *vc,int speed){
    evc
}

void car_drive(char *s){
    printf("car_drive:%s",s);
}

void car_acclerate(int speed){
    printf("c_a act=%d",speed);
}

void car_break(int speed){
    printf("c_b act=%d",speed);
}

void run(){

}

int main(){
    struct vehicle car;
    car.drive=car_drive;
    car.acclerate=car_acclerate;
    car.brake=car_break;
    car.wheel=4;
    car.door=4;
}