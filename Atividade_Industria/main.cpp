#include <iostream>
#include "controlador_motor.h"
#include "sensor_temperatura.h"
#include "robo_manipulador.h"
#include "sistema_controle.h"
#include <chrono>
#include <thread>
#include <unistd.h> // sleep()



using namespace std;

int main() {
    // Sistema de controle
    sistema_controle sistema;

    // Dispositivos industriais
    controlador_motor* mt1 = new controlador_motor("mt1", 32, 250, 2000);
    sensor_temperatura* s1 = new sensor_temperatura("s1", 32, 27, 69);
    robo_manipulador* r1 = new robo_manipulador("r1", 32, 45);

    sistema.adicionar_dispositivo(mt1);
    sistema.adicionar_dispositivo(s1);
    sistema.adicionar_dispositivo(r1);


    thread motor_thread(&controlador_motor::iniciar, mt1);
    mt1->ajustar_velocidade(2000); 
    sleep(1);

    mt1->ajustar_velocidade(2500); 
    sleep(1);

    mt1->ajustar_velocidade(2500);  
    sleep(1);

    mt1->ajustar_velocidade(3000);  
    sleep(1); 

    mt1->ajustar_velocidade(25000); 

    motor_thread.join();


    thread sensor_thread(&sensor_temperatura::iniciar, s1);

    s1->setTemperatura(32.0);
    sleep(1);

    s1->setTemperatura(55.0);
    sleep(1);

    s1->setTemperatura(62.0);

    s1->setTemperatura(33.0);
    sleep(1);
    
    s1->parar();
    sensor_thread.join();

    thread robo_thread(&robo_manipulador::iniciar, r1);

    r1->mover_para(10.0, 20.0, 30.0);
    sleep(1);

    r1->mover_para(15.0, 25.0, 35.0);
    sleep(1);

    r1->agarrar_objeto(25.0);
    sleep(1);
  
    r1->agarrar_objeto(100.0); 
    
    r1->soltar_objeto();
    sleep(1);

    r1->gerar_relatorio();

    r1->parar();

    robo_thread.join();

    sistema.iniciar_todos();
    sistema.gerar_relatorio_completo();
    sistema.parar_todos();

    return 0;
}
