#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include <string>
#include "dispositivo_industrial.h"

using namespace std;

class sensor_temperatura : public dispositivo_industrial {
private:
    double t_max;
    double t_min;
    double temp_atual;
    string informacao;

public:
    sensor_temperatura(const string& i, double temp_celsius, double temp_min, double temp_max) : dispositivo_industrial(i, temp_celsius),
    t_min(temp_min), t_max(temp_max) {}

    bool alerta_temperatura();
    void iniciar() override;
    void parar() override;
    string gerar_relatorio() override;
};

#endif // SENSOR_TEMPERATURA_H
