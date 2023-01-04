/*
 * ContextData.h
 *
 *  @author Johannes Oehlers
 *  @author Björn Leuendorf
 */

#ifndef SRC_FSM_GOF_CONTEXTDATA_H_
#define SRC_FSM_GOF_CONTEXTDATA_H_

#include <iostream>
#include <time.h>
#include <list>
#include <ctime>
#include <chrono>
#include <sys/dispatch.h>
#include "../../utils/Events.h"
#include "../Connected/OperatingMode/Run/MeasurePolling.h"

//includes for cfg
#include <string.h>
#include <fstream>
#include "json.hpp"

#include <typeinfo>

using json = nlohmann::json;

//struct für Werkstückverwaltung
struct workpiece {
	int id;
	int type;
	bool metal;
	float height;
	bool flipped;
	int segment;
	double distance;
};


/*
 * (vgl. GOF Pattern)
 * Datenspeicher
 */
class ContextData {
public:
	ContextData(); // Konstruktor für die Klasse ContextData
	virtual ~ContextData(); // Destruktor für die Klasse ContextData

	MeasurePolling mp("cr");
	
	void setCoid(int con);
//	void setCoid(int id);
	void setCoidExt(int id);
	int getCoid();
	int getCoidExt();

	void setLoadedConfTrue();
	void setLoadedConfFalse();
	bool getLoadedConf();

	void setConnectionTrue();
	void setConnectionFalse();
	bool getConnection();

	void setEstopSelfTrue();
	void setEstopSelfFalse();
	bool getEstopSelf();

	void setEstopExtTrue();
	void setEstopExtFalse();
	bool getEstopExt();

	void setAppearedTrue();
	void setAppearedFalse();
	bool getAppeared();

	void setDisappearedTrue();
	void setDissapearedFalse();
	bool getDissapeared();

	void incCurrentCount();
	void decCurrentCount();
	int getCurrentCount();

	void setWP_ExpectedTrue();
	void setWP_ExpectedFalse();
	bool getWP_Expected();

	void setFesto(int festoNr);
	void setFestoSelf();
	void setFestoExt();
	int getFesto();
	void setFestoExtFree(bool f);
	bool getFestoExtFree();

	void setSlExtTrue();
	void setSlExtFalse();
	bool getSlExt();

	void setSlSelfTrue();
	void setSlSelfFalse();
	bool getSlSelf();

	std::list<workpiece> wpList;
	double segmentDistanceList[3] = {0, 0, 0};

	double slowFactor = 0;

	bool motor = false;
	bool motorSlow = false;
	bool motorStop = false;
	void addWs(int id, int type, int height);
	void addWsExt(int id, int height);

	void setWpId(int id);

	void setLoadConfig();
	//Setter for WP A
	void setWpHighATrue();
	void setWpHighAFalse();
	void setWpDrillingATrue();
	void setWpDrillingAFalse();
	void setWpIsMetalATrue();
	void setWpIsMetalAFalse();
	//Setter for WP B
	void setWpHighBTrue();
	void setWpHighBFalse();
	void setWpDrillingBTrue();
	void setWpDrillingBFalse();
	void setWpIsMetalBTrue();
	void setWpIsMetalBFalse();
	//Setter for WP C
	void setWpHighCTrue();
	void setWpHighCFalse();
	void setWpDrillingCTrue();
	void setWpDrillingCFalse();
	void setWpIsMetalCTrue();
	void setWpIsMetalCFalse();

	//Getter for WP A
	int getWpHighA();
	int getWpDrillingA();
	int getWpIsMetalA();
	//Getter for WP B
	int getWpHighB();
	int getWpDrillingB();
	int getWpIsMetalB();
	//Getter for WP C
	int getWpHighC();
	int getWpDrillingC();
	int getWpIsMetalC();
	
	
	static int coid;
	static bool blinkGreen;
	static bool blinkYellow;
	static bool blinkRed;
	static bool blinkQ1;
	static bool blinkQ2;
	static bool blinkStart;
	static bool blinkReset;

private:
	// Workpiece A
	bool highA = false;
	bool drillingA = false;
	bool isMetalA = false;
	// Workpiece B
	bool highB = false;
	bool drillingB = false;
	bool isMetalB = false;
	// Workpiece C
	bool highC = false;
	bool drillingC = false;
	bool isMetalC = false;

	
	std::list<time_t> timerHeightQueue;
	std::list<time_t> timerEndQueue;
	std::list<time_t> timerWeicheOeffnenQueue;


	//coid
//	int coid;
	int coidExt;
	//Connection
	bool loadedConf = false;
	//Overview
	bool connection = false;
	//EStop
	bool eStopSelf = false;
	bool eStopExt = false;
	//Error
	bool appeared = false;
	bool disappeared = false;
	//Operating Mode
	int currentCount = 0;
	//throw
	bool wp_expected = false;
	int festo = 0;
	//Festo
	bool festoExtFree = true;

	//Slide
	bool slExt = true;
	bool slSelf = true;

};

#endif /* SRC_FSM_GOF_CONTEXTDATA_H_ */
