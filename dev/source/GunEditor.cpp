#include <conio.h>
#include <fstream> 
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "Gun.hpp"

//Conversoes string
// De char[] para string
// string name_temp(name);

// De string para char[]
// cout<<"\nnome: "; cin>>name_temp;
// strncpy(name, name_temp.c_str(), sizeof(name));
// name[sizeof(name)-1] = 0;

using namespace std;

class GunEditor : public Gun {
public:
	GunEditor(){}

	void nova(){
		cout<<"\nEditor de armas - Cadastro\n";
		cout<<"\nId: "; cin>>id;
		fflush(stdin);
		//getchar();
		cout<<"Nome: "; cin.getline(name,50);;
		cout<<"Distancia(0-Corpo a Corpo 1-Perto 2-Medio 3-Longo): "; cin>>range;
		cout<<"Cadencia(0-N\\A 1-Baixa 2-Media 3-Alta): "; cin>>cadence;
		cout<<"Dano(1-Baixo 2-Medio 3-Alto): "; cin>>damage;
		cout<<"Peso(1-Nulo 2-Leve 3-Pesado): "; cin>>weight;
	}

	void print(){
		// cout<<"ID "<<setw(30)<<left<<"NOME "<<" DISTANCIA "<<" CADENCIA "<<" DANO "<<" PESO"<<endl;
		cout<<setw(3)<<id<<setw(31)<<name<<setw(11)<<range<<setw(10)<<cadence<<setw(6)<<damage<<weight<<endl;
	}

	int getId(){
		return id;
	}

	void altearCampo(int campo){
		string name_temp;

		switch(campo){
			case 1:
				cout<<"Nao e possivel alterar o atributo ID";
			case 2:
				fflush(stdin);
				cout<<"Nome: "; cin.getline(name,50);;
				break;
			case 3:
				cout<<"Distancia(0-Corpo a Corpo 1-Perto 2-Medio 3-Longo): "; cin>>range;
				break;
			case 4:
				cout<<"Cadencia(0-N\\A 1-Baixa 2-Media 3-Alta): "; cin>>cadence;
				break;
			case 5:
				cout<<"Dano(1-Baixo 2-Medio 3-Alto): "; cin>>damage;
				break;
			case 6:
				cout<<"Peso(1-Nulo 2-Leve 3-Pesado): "; cin>>weight;
				break;
			default:
				cout<<"Coluna nao encontrada"<<endl;
		}
	}
};

void reorg(){
	vector<GunEditor> gunV1;
	vector<int> idV;
	vector<GunEditor> gunV2;
	GunEditor gun;
	GunEditor gunT;

	ifstream fin("gun.dat", std::ofstream::binary);
	while (fin.read((char *)&gun, sizeof(Gun))){   // lê do arquivo 
  		gunV1.push_back(gun);
  		idV.push_back(gun.getId());
  	}
  	fin.close();

  	std::sort (idV.begin(), idV.begin()+idV.size()); 

	for(int i=0;i<idV.size();i++){
		for(int j=0;j < gunV1.size();j++){
			if(gunV1[j].getId() == idV[i]){
				gunV2.push_back(gunV1[j]);
			}
		}		
	}

	ofstream fout("gun.dat", std::ofstream::binary);
	for(int i=0;i < gunV2.size();i++){
	    fout.write((char *)&gunV2[i], sizeof(Gun));  // grava no arquivo 
	}
 	fout.close();	
}

void cadastro(){
	GunEditor gun;

	ofstream fout("gun.dat", std::ofstream::binary | std::ofstream::app);
	do{
		gun.nova();
	    fout.write((char *)&gun, sizeof(Gun));  // grava no arquivo 
  		cout << "\nInserir outra arma(s/n) ";    
  	}while(getche() != 'n'); 
  	fout.close();
  	reorg();
  	system("cls");
}

void leitura(){
	GunEditor gun;

	cout<<"\nEditor de armas - Leitura\n";
	cout<<"\nID "<<setw(30)<<left<<"NOME "<<" DISTANCIA "<<" CADENCIA "<<" DANO "<<" PESO"<<endl;
	ifstream fin("gun.dat", std::ofstream::binary);
	while (fin.read((char *)&gun, sizeof(Gun)))   // lê do arquivo 
  		gun.print();
  	fin.close();
  	cout<<endl;
  	system("pause");
  	system("cls");
}

void remover(){
	vector<GunEditor> gunV;
	GunEditor gun;
	int id;

	cout<<"\nEditor de armas - Remover\n";
	cout<<"\nID "<<setw(30)<<left<<"NOME "<<" DISTANCIA "<<" CADENCIA "<<" DANO "<<" PESO"<<endl;
	ifstream fin("gun.dat", std::ofstream::binary);
	while (fin.read((char *)&gun, sizeof(Gun))){   // lê do arquivo 
  		gun.print();
  		gunV.push_back(gun);
	}
  	fin.close();
	
  	cout<<"\nDigite o ID da arma que deseja remover ou digite 0 para cancelar: ";
  	cin>>id;


  	if(id != 0){
  		cout<<"Deseja continuar(s/n): ";
  		if(getche() != 'n'){
			ofstream fout("gun.dat", std::ofstream::binary);
			for(int i=0;i < gunV.size();i++){
				if(gunV[i].getId() != id){
			    	fout.write((char *)&gunV[i], sizeof(Gun));  // grava no arquivo 
			    }
			}
		  	fout.close();	
	  	}
  	}
  	system("cls");
}

void alterar(){
	int id, col;
	vector<GunEditor> gunV;
	GunEditor gun;

	cout<<"\nEditor de armas - Alterar\n";
	cout<<"\nID "<<setw(30)<<left<<"NOME "<<" DISTANCIA "<<" CADENCIA "<<" DANO "<<" PESO"<<endl;
	ifstream fin("gun.dat", std::ofstream::binary);
	while (fin.read((char *)&gun, sizeof(Gun))){   // lê do arquivo 
  		gun.print();
  		gunV.push_back(gun);
  	}
  	fin.close();

	cout<<"\nDigite o ID da arma que deseja alterar ou digite 0 para cancelar: ";
  	cin>>id;

  	if(id != 0){
  		cout<<"Entre com a coluna que deseja alterar: "; cin>>col;
		ofstream fout("gun.dat", std::ofstream::binary);
		for(int i=0;i < gunV.size();i++){
			if(gunV[i].getId() == id){
				gunV[i].altearCampo(col);
				cout<<endl;
				gunV[i].print();
				cout<<endl;
		    }
		    fout.write((char *)&gunV[i], sizeof(Gun));  // grava no arquivo 
		}
	  	fout.close();	
  	}
  	system("pause");
  	system("cls");

}


int main(){
	int option;

	do{
		cout<<"\nEditor de armas - Menu\n"<<endl;

		cout<<"1-Cadastro"<<endl;
		cout<<"2-Leitura"<<endl;
		cout<<"3-Remover"<<endl;
		cout<<"4-Alterar"<<endl;
		cout<<"9-Sair"<<endl;

		cout<<"\nSelecione sua opcao: "; cin>>option;

		system("cls");

		switch(option){
			case 1:
				cadastro();
				break;
			case 2:
	  			leitura();
				break;
			case 3:
	  			remover();
				break;
			case 4:
	  			alterar();
				break;
			case 99:
	  			reorg();
				break;
			case 9:
				return 0;
			default:
				cout<<"Opcao invalida!\n";
				break;
	  	}
	  }while(option != 9);
}