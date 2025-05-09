    #ifndef CONTROLADOR_MOTOR_H
    #define CONTROLADOR_MOTOR_H

    #include <string>
    #include "dispositivo_industrial.h"
    #include <iostream>
    #include <string>

    using namespace std;

    class controlador_motor : public dispositivo_industrial {
    private:
        int potencia;
        int rpm;
        double horas_de_uso;
        string informacao;
        string aviso;
    public:
        controlador_motor(const string& i, double temp_celsius, int p, int r) : dispositivo_industrial(i, temp_celsius), potencia(p), rpm(r), horas_de_uso(0) { }
        void ajustar_velocidade(int nova_rpm);
        double calcular_eficiencia();
        bool verificar_seguranca() override;
        void iniciar() override;
        void parar() override;
        string gerar_relatorio() override;

    };

    #endif // CONTROLADOR_MOTOR_H
