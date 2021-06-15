#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

             
int main(){
    vector<float> min_options;
    float distance, delta_distance = 0, last_distance = 0, rate_consumption = 0, leak_count = 0, min_volume = 0;
    string line;
    size_t found;
    string temp;

    while(getline(cin, line)){
        //CASO FINAL
        if (line.find("0 Fuel consumption 0") != string::npos){
            break;
        }
        else{
        /*CONSIDERO UN PARAMETRO DE VOLÚMEN MINIMO UTILIZADO PARA OBTENER LA MINIMA CAPACIDAD NECESARIA. (MINIMO += DISTANCIA * FACTORCONSUMO)
        ENTONCES HASTA QUE APAREZCA UN EVENTO DE "Gas station" o un "Goal" GUARDO EL VALOR DE COMBUSTIBLE UTILIZADO Y FINALMENTE
        OBTENGO LA MINIMA CAPACIDAD DE TANQUE MEDIANTE EL MAXIMO VALOR DE LOS GUARDADOS EN ESTOS TRAYECTOS */
            if(line.find("Fuel consumption") != string::npos){
                found = line.find_first_of(" ");
                temp = line.substr(0, found);
                distance = stof(temp);
                delta_distance = distance - last_distance;
                if(rate_consumption!=0){
                    if(last_distance==distance){
                        found = line.find_last_of(" ");
                        temp = line.substr(found + 1);
                        rate_consumption = stof(temp);
                        rate_consumption = (rate_consumption / 100) + leak_count;
                        min_volume += delta_distance * rate_consumption;
                        last_distance = distance;
                        continue;
                    }
                    min_volume += delta_distance * rate_consumption;
                    found = line.find_last_of(" ");
                    temp = line.substr(found + 1);
                    rate_consumption = stof(temp);
                    rate_consumption = (rate_consumption / 100) + leak_count;
                    last_distance = distance;
                    continue;
                }
                found = line.find_last_of(" ");
                temp = line.substr(found + 1);
                rate_consumption = stof(temp);
                rate_consumption = (rate_consumption / 100);
                min_volume += delta_distance * rate_consumption;
                last_distance = distance;
            }
            else if(line.find("Goal") != string::npos){
                found = line.find_first_of(" ");
                temp = line.substr(0, found);
                distance = stof(temp);
                delta_distance = distance - last_distance;

                min_volume += delta_distance * rate_consumption;
                min_options.push_back(min_volume);

                //EL MAXIMO VALOR ES LA MINIMA CAPACIDAD DE TANQUE NECESARIA
                auto min_value = *std::max_element(min_options.begin(), min_options.end());
                printf("%.3f\n", min_value);
                min_volume = 0;
                delta_distance = 0;
                last_distance = 0;
                leak_count = 0;
                rate_consumption = 0;
                min_options.clear();
            }
            else if(line.find("Leak") != string::npos){
                found = line.find_first_of(" ");
                temp = line.substr(0, found);
                distance = stof(temp);
                if(last_distance==distance){
                    leak_count++;
                    rate_consumption += 1;
                    continue;
                }
                delta_distance = distance - last_distance;
                min_volume += (delta_distance * rate_consumption);
                leak_count++;
                rate_consumption += 1;
                last_distance = distance;
            }
            else if(line.find("Mechanic") != string::npos){
                found = line.find_first_of(" ");
                temp = line.substr(0, found);
                distance = stof(temp);
                if(last_distance==distance){
                    rate_consumption -= leak_count;
                    leak_count = 0;
                    continue;
                }
                delta_distance = distance - last_distance;
                min_volume += (delta_distance * rate_consumption);
                rate_consumption -= leak_count;
                leak_count = 0;
                last_distance = distance;
            }
            else if(line.find("Gas") != string::npos){
                found = line.find_first_of(" ");
                temp = line.substr(0, found);
                distance = stof(temp);
                if(last_distance==distance){
                    min_options.push_back(min_volume);
                    min_volume = 0;
                    continue;
                }
                delta_distance = distance - last_distance;
                min_volume += (delta_distance * rate_consumption);
                min_options.push_back(min_volume);
                min_volume = 0;
                last_distance = distance;
            }
        }
    }
    return 0;
}