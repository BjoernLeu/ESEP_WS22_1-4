/*
 * ContextData.h
 *
 *  @author Johannes Oehlers
 *  @author Björn Leuendorf
 */

#ifndef SRC_FSM_GOF_CONTEXTDATA_H_
#define SRC_FSM_GOF_CONTEXTDATA_H_

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <list>
#include <vector>
#include <iterator>
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

	std::vector<workpiece> wpList;

	int getNumberWpsOnBelt();

	// void setWPType(int type);
	// int getWPType();
	// void setWPMetal(bool metal);
	// bool getWPMetal();
	// void setWPHeight(float height);
	// float getWPHeight();
	// void setWPFlipped(bool flipped);
	// bool getWPFlipped();
	// int getWPSegment();
	// double distance;
	double segmentDistanceList[3] = {0, 0, 0};

	double slowFactor = 0;

	bool motor = false;
	bool motorSlow = false;
	bool motorStop = false;

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

	//Timer WP-Tracking
	void setTime_lbI_fast_max();
	void setTime_hsWP_fast_max();
	void setTime_lbSW_fast_max();
	void setTime_lbO_fast_max();

	void setTime_lbI_fast_min();
	void setTime_hsWP_fast_min();
	void setTime_lbSW_fast_min();
	void setTime_lbO_fast_min();

	void setTime_lbI_slow();
	void setTime_hsWP_slow();

	void setSectorDiff_max();
	void setSectorDiff_min();

	double getS1Max();
	double getS2Max();
	double getS3Max();

	double getS1Min();
	double getS2Min();
	double getS3Min();

	void setSlowDur();
	double getSlowDur();

	void setSlowFactor();
	double getSlowFactor();

//================= WP LIST =================
	void incWpCount();
	void decWpCount();
	int getWpCount();

	void addWp(int type, bool metal, float height, bool flipped, int segment, double distance);
	void popWp();
	workpiece getWp();
	bool getWpEmpty();
	void addWpMetal();
	bool getWpMetal();
	void addWpType(int type, int height);
	void addFlipped();
	
	MeasurePolling* mp;

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

	//Timer WP-Tracking
	std::chrono::time_point<std::chrono::system_clock> lbI_fast_max, hsWP_fast_max, lbSW_fast_max, lbO_fast_max;
	std::chrono::time_point<std::chrono::system_clock> lbI_fast_min, hsWP_fast_min, lbSW_fast_min, lbO_fast_min;
	std::chrono::time_point<std::chrono::system_clock> lbI_slow_max, hsWP_slow_max;

	//Sectors
	std::chrono::duration<double> s1_length_max;
	std::chrono::duration<double> s2_length_max;
	std::chrono::duration<double> s3_length_max;
	std::chrono::duration<double> s1_length_min;
	std::chrono::duration<double> s2_length_min;
	std::chrono::duration<double> s3_length_min;

	std::chrono::duration<double> slowDur;

	//Lists
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
	int wpCount = 0;
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
