/*
 *   ____ _       _       _            _  ____ 
 *  / ___| |__  _ __(_)___| | ___  ___   | |/ ___|
 * | |   | '_ \| '__| / __| |/ _ \/ __|  | | |    
 * | |___| | | | |  | \__ \ | (_) \__ \_ | | |___ 
 *  \____|_| |_|_|  |_|___/_|\___/|___/__/ |\____|
 *                                    |__/        
 *
 * Autor: Chris Joseph Jean Carty (@ChrisJosJC)
 * Fecha: 2026-11-07
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double sueldoBruto = 0.0;
    
    while (sueldoBruto <= 0) {
        cout << "Ingrese el sueldo mensual bruto del empleado (RD$): ";
        cin >> sueldoBruto;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            sueldoBruto = 0;
            cout << "Error: Por favor ingrese un numero valido." << endl;
        } else if (sueldoBruto <= 0) {
            cout << "Error: El sueldo debe ser mayor a 0." << endl;
        }
    }
    
    double descuentoTSS = sueldoBruto * 0.0591;
    double salarioImponible = sueldoBruto - descuentoTSS;
    
    double salarioAnual = salarioImponible * 12;
    double isrAnual = 0.0;
    
    if (salarioAnual <= 416220.00) {
        isrAnual = 0.0;
    } 
    else if (salarioAnual <= 624329.00) {
        isrAnual = (salarioAnual - 416220.00) * 0.15;
    } 
    else if (salarioAnual <= 867123.00) {
        isrAnual = 31216.00 + ((salarioAnual - 624329.00) * 0.20);
    } 
    else {
        isrAnual = 79776.00 + ((salarioAnual - 867123.00) * 0.25);
    }
    
    double isrMensual = isrAnual / 12.0;
    
    cout << fixed << setprecision(2);
    cout << "\n===== DESGLOSE SALARIAL (Escala DGII 2026) =====" << endl;
    cout << "Sueldo Bruto Mensual   : RD$ " << sueldoBruto << endl;
    cout << "Descuento TSS (5.91%)  : RD$ " << descuentoTSS << endl;
    cout << "Salario Base Imponible : RD$ " << salarioImponible << endl;
    
    cout << "Descuento ISR Mensual  : ";
    if (isrMensual > 0) {
        cout << "RD$ " << isrMensual << endl;
    } else {
        cout << "0 (N/A - Exento)" << endl;
    }
    
    double sueldoNeto = salarioImponible - isrMensual;
    cout << "Sueldo Neto a Recibir  : RD$ " << sueldoNeto << endl;
    cout << "================================================" << endl;
    
    cout << "\nPresione Enter para salir...";
    cin.ignore(10000, '\n');
    cin.get();
    
    return 0;
}