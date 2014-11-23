#include "Wave.hpp"

Wave::Wave(){

}

Wave::Wave(int waveNum, float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader, Display * dis){
	int numSoin = 0, numCabra = 0, numTatu = 0, numCorrupiao = 0;
	int numFacao = 0, numLuger = 0, numColt = 0, numWinchester = 0, numMouser = 0;

	float vel1 = 0.3;
	float vis1 = 50;
	float hp1 = 50;
	float xp1 = 5;

	float vel2 = 0.2;
	float vis2 = 25;
	float hp2 = 100;
	float xp2 = 10;

	float vel3 = 0.4;
	float vis3 = 70;
	float hp3 = 80;
	float xp3 = 15;

	idWave = waveNum;

	switch (waveNum){
	case 1:
		// numSoin = 10; numCabra = 10; numTatu = 0; numCorrupiao = 0;
		// numFacao = 10; numLuger = 10; numColt = 0; numWinchester = 0; numMouser = 0;
		numSoin = 2; numCabra = 2; numTatu = 0; numCorrupiao = 0;
		numFacao = 1; numLuger = 1; numColt = 0; numWinchester = 0; numMouser = 0;

		// Construct method of CharEnemmy:
		// CharEnemmy(Display, screen_x, screen_y, collisionManager, mapLoader, hp, xp, gun, vel, type, visionRange)

		for(int i = 0; i < numSoin; i++){	
			if(i < numSoin/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 1, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 2, vis1);
				if(i == 1){
					enemmy->setDropGun(true);
				}
				waveEnemmies.push_back(enemmy);
			}
		}

		for(int i = 0; i < numCabra; i++){
			if(i < numCabra/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 1, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 1, vis1);
				if(i == 1){
					enemmy->setDropGun(true);
				}
				waveEnemmies.push_back(enemmy);
			}
		}


	break;
	//===================================================================================
	case 2:
		numSoin = 15; numCabra = 15; numTatu = 0; numCorrupiao = 0;
		numFacao = 20; numLuger = 10; numColt = 0; numWinchester = 0; numMouser = 0;

		for(int i = 0; i < numSoin; i++){
			if(i < numFacao/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 1, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}
		}

		for(int i = 0; i < numCabra; i++){
			if(i < numFacao/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 1, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}
		}

	break;
	//===================================================================================
	case 3:
		numSoin = 15; numCabra = 15; numTatu = 0; numCorrupiao = 0;
		numFacao = 0; numLuger = 0; numColt = 20; numWinchester = 5; numMouser = 5;

		for(int i = 0; i < numSoin; i++){
			if(i < numColt/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				if(i < 12){
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 5, vel1, 2, vis1);
					waveEnemmies.push_back(enemmy);
				}else{
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 2, vis1);
					waveEnemmies.push_back(enemmy);
				}
			}
		}

		for(int i = 0; i < numCabra; i++){
			if(i < numColt/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				if(i < 13){
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 5, vel1, 1, vis1);
					waveEnemmies.push_back(enemmy);
				}else{
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 1, vis1);
					waveEnemmies.push_back(enemmy);
				}
			}
		}

	break;
	//===================================================================================
	case 4:
		numSoin = 10; numCabra = 10; numTatu = 10; numCorrupiao = 0;
		numFacao = 0; numLuger = 20; numColt = 0; numWinchester = 5; numMouser = 5;

		for(int i = 0; i < numSoin; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 2, vis1);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numCabra; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 1, vis1);
			waveEnemmies.push_back(enemmy);

		}

		for(int i = 0; i < numTatu; i++){
			if(i < numTatu/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 4, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 5, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}

		}

	break;
	//===================================================================================
	case 5:
		numSoin = 10, numCabra = 10, numTatu = 5, numCorrupiao = 0;
		numFacao = 0, numLuger = 0, numColt = 10, numWinchester = 10, numMouser = 10;

		for(int i = 0; i < numSoin; i++){
			if(i < numSoin/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 2, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				if(i < 8){
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 2, vis1);
					waveEnemmies.push_back(enemmy);
				}else{
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 5, vel1, 2, vis1);
					waveEnemmies.push_back(enemmy);
				}
			}
		}

		for(int i = 0; i < numCabra; i++){
			if(i < numCabra/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 2, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				if(i < 7){
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 1, vis1);
					waveEnemmies.push_back(enemmy);
				}else{
					CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 5, vel1, 1, vis1);
					waveEnemmies.push_back(enemmy);
				}
			}

		}

		for(int i = 0; i < numTatu; i++){
			if(i < numTatu/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 4, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 5, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}

		}

	break;
	//===================================================================================
	case 6:
		numSoin = 10, numCabra = 10, numTatu = 10, numCorrupiao = 1;
		numFacao = 0; numLuger = 20; numColt = 1; numWinchester = 5; numMouser = 5;

		for(int i = 0; i < numSoin; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 2, vis1);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numCabra; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 1, vis1);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numCorrupiao; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp3, xp3, 2, vel3, 4, vis3);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numTatu; i++){
			if(i < numTatu/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 4, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 5, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}

		}

	break;
	//===================================================================================
	case 7:
		numSoin = 10, numCabra = 10, numTatu = 10, numCorrupiao = 5;
		numFacao = 0; numLuger = 0; numColt = 20; numWinchester = 10; numMouser = 5;

		for(int i = 0; i < numSoin; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 2, vel1, 2, vis1);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numCabra; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 2, vel1, 1, vis1);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numCorrupiao; i++){
			if(i < numCorrupiao/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp3, xp3, 4, vel3, 4, vis3);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp3, xp3, 5, vel3, 4, vis3);
				waveEnemmies.push_back(enemmy);
			}

		}

		for(int i = 0; i < numTatu; i++){
			if(i < numTatu/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 4, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 5, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}
		}

	break;
	//===================================================================================
	case 8:
		numSoin = 10, numCabra = 10, numTatu = 10, numCorrupiao = 5;
		numFacao = 0; numLuger = 0; numColt = 0; numWinchester = 20; numMouser = 15;

		for(int i = 0; i < numSoin; i++){
			if(i < numSoin/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 5, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}
		}

		for(int i = 0; i < numCabra; i++){
			if(i < numCabra/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 5, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}
		}

		for(int i = 0; i < numCorrupiao; i++){
			if(i < numCorrupiao/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp3, xp3, 4, vel3, 4, vis3);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp3, xp3, 5, vel3, 4, vis3);
				waveEnemmies.push_back(enemmy);
			}

		}

		for(int i = 0; i < numTatu; i++){
			if(i < numTatu/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 4, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 5, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}

		}

	break;
	//===================================================================================
	case 9:
		numSoin = 10, numCabra = 10, numTatu = 10, numCorrupiao = 1;
		numFacao = 0; numLuger = 20; numColt = 0; numWinchester = 5; numMouser = 5; // 1 hotchkiss

		for(int i = 0; i < numSoin; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 2, vis1);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numCabra; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 3, vel1, 1, vis1);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numCorrupiao; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp3, xp3, 6, vel3, 4, vis3);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numTatu; i++){
			if(i < numTatu/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 4, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 5, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}

		}

	break;
	//===================================================================================
	case 10:
		numSoin = 10, numCabra = 10, numTatu = 10, numCorrupiao = 5;
		numFacao = 0; numLuger = 0; numColt = 0; numWinchester = 15; numMouser = 15; // 5 hotchkiss

		for(int i = 0; i < numSoin; i++){
			if(i < numSoin/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 6, vel1, 2, vis1);
				waveEnemmies.push_back(enemmy);
			}
		}

		for(int i = 0; i < numCabra; i++){
			if(i < numCabra/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 4, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp1, xp1, 5, vel1, 1, vis1);
				waveEnemmies.push_back(enemmy);
			}
		}

		for(int i = 0; i < numCorrupiao; i++){
			CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp3, xp3, 6, vel3, 4, vis3);
			waveEnemmies.push_back(enemmy);
		}

		for(int i = 0; i < numTatu; i++){
			if(i < numTatu/2){
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 4, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}else{
				CharEnemmy * enemmy = new CharEnemmy(dis, screen_x, screen_y, cManager, mapLoader, hp2, xp2, 5, vel2, 3, vis2);
				waveEnemmies.push_back(enemmy);
			}
		}

	break;
	//===================================================================================
	default:
		std::cout << "Numero de wave nao informado corretamente"<<std::endl;
	break;
	}
}

//getters and setters
void Wave::setIdWave(int neWaveId){
	idWave = neWaveId;
}
//-------------------
int Wave::getIdWave(int neWaveId){
	return idWave;
}

std::vector<CharEnemmy *> Wave::getWaveEnemmies(){
    return waveEnemmies;
}

// std::vector<int> Wave::getIdColisionObjects(){
	
// 	std::vector<int> listaIDs;
	
// 	for(int i = 0; i < waveEnemmies.size(); i++){
// 		listaIDs.push_back(waveEnemmies[i]->id);
// 	}
	
// 	return listaIDs;
// }
