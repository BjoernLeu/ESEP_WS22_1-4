/*
 * ContextData.cpp
 *
 * @author Johannes Oehlers
 * @author Björn Leuendorf
 */

#include "ContextData.h"

ContextData::ContextData() {}
ContextData::~ContextData() {}

/*================coid================*/
int ContextData::coid;
bool ContextData::blinkGreen;
bool ContextData::blinkYellow;
bool ContextData::blinkRed;
bool ContextData::blinkQ1;
bool ContextData::blinkQ2;
bool ContextData::blinkStart;
bool ContextData::blinkReset;


void ContextData::setCoid(int con){ContextData::coid = con;}
//void ContextData::setCoid(int id) {coid = id;}
void ContextData::setCoidExt(int id) {coidExt = id;}
int ContextData::getCoid() {return coid;}
int ContextData::getCoidExt() {return coidExt;}

/*================LoadedConf================*/
void ContextData::setLoadedConfFalse(){loadedConf = true;}
void ContextData::setLoadedConfTrue(){loadedConf = false;}
bool ContextData::getLoadedConf(){return loadedConf;}

/*================Connection================*/
void ContextData::setConnectionTrue(){connection = true;}
void ContextData::setConnectionFalse(){connection = false;}
bool ContextData::getConnection(){return connection;}

/*================EStop Self================*/
void ContextData::setEstopSelfTrue(){eStopSelf = true;}
void ContextData::setEstopSelfFalse(){eStopSelf = false;}
bool ContextData::getEstopSelf(){return eStopSelf;}

/*================EStop Ext================*/
void ContextData::setEstopExtTrue(){eStopExt = true;}
void ContextData::setEstopExtFalse(){eStopExt = false;}
bool ContextData::getEstopExt(){return eStopExt;}

/*================Appeared================*/
void ContextData::setAppearedTrue(){appeared = true;}
void ContextData::setAppearedFalse(){appeared = false;}
bool ContextData::getAppeared(){return appeared;}

/*================Disappeared================*/
void ContextData::setDisappearedTrue(){disappeared = true;}
void ContextData::setDissapearedFalse(){disappeared = false;}
bool ContextData::getDissapeared(){return disappeared;}

/*================Current Count================*/
void ContextData::incCurrentCount(){currentCount++;}
void ContextData::decCurrentCount(){currentCount--;}
int ContextData::getCurrentCount(){return currentCount;}

/*================WP_Expected================*/
void ContextData::setWP_ExpectedTrue(){wp_expected = true;}
void ContextData::setWP_ExpectedFalse(){wp_expected = false;}
bool ContextData::getWP_Expected(){return wp_expected;}

/*================Festo================*/
void ContextData::setFesto(int festoNr){festo = festoNr;}
void ContextData::setFestoSelf(){festo = 1;}
void ContextData::setFestoExt(){festo = 2;}
int ContextData::getFesto(){return festo;}
void ContextData::setFestoExtFree(bool f) {festoExtFree = f;}
bool ContextData::getFestoExtFree() {return festoExtFree;}

/*================Slide - SlExt================*/
void ContextData::setSlExtTrue(){slExt = true;}
void ContextData::setSlExtFalse(){slExt = false;}
bool ContextData::getSlExt(){return slExt;}

/*================Slide - SlSelf================*/
void ContextData::setSlSelfTrue(){slSelf = true;}
void ContextData::setSlSelfFalse(){slSelf = false;}
bool ContextData::getSlSelf(){return slSelf;}

///*================WP================*/
//void ContextData::addWs(int id, int type, int height) {
//	wsList.push_back({id, type, height, false, false});
//	std::cout << "WS added" << std::endl;
//}
//void ContextData::addWsExt(int id, int height) {
//	wsListExt.push_back({id, height, false, false});
//	std::cout << "WS added" << std::endl;
//}
//void ContextData::setWsId(int id) {wsList.back().id = id;}
//void ContextData::addWsMetal() {wsList.front().metal = true;}
//void ContextData::addWsSort() {wsList.back().sort = true;}
//void ContextData::popWs() {wsList.pop_front();}
//bool ContextData::getWsEmpty() {return wsList.empty();}
//bool ContextData::getWsSort() {return wsList.front().sort;}
//Werkstueck ContextData::getWs() {return wsList.front();}
//void ContextData::addWsMetalExt() {wsListExt.front().metal = true;}
//void ContextData::addWsSortExt() {wsListExt.back().sort = true;}
//void ContextData::popWsExt() {wsListExt.pop_front();}
//void ContextData::clearWsList(){wsListExt.clear();}
//std::list<Werkstueck> ContextData::getWsList(){return wsListExt;}
//bool ContextData::getWsEmptyExt() {return wsListExt.empty();}
//bool ContextData::getWsSortExt() {return wsListExt.front().sort;}
//bool ContextData::getWsMetal(){
//	std::cout << "metall: " << wsList.front().metal << std::endl;
//	return wsList.front().metal;
//}
//void ContextData::setWsExt(Werkstueck w) {wsExt = w;}
//void ContextData::setTypeExt(int t) {typeExt = t;}
//void ContextData::setHeightExt(int h) {heightExt = h;}
//void ContextData::setMetalExt(bool m) {metalExt = m;}
//void ContextData::setSortExt(bool s) {sortExt = s;}
//Werkstueck ContextData::getWsExt() {return wsExt;}
//int ContextData::getTypeExt() {return typeExt;}
//int ContextData::getHeightExt() {return heightExt;}
//bool ContextData::getMetalExt() {return metalExt;}
//bool ContextData::getSortExt() {return sortExt;}
//void ContextData::setWpId(int id) {wsList.back().id = id;}
/*================Setter for WP A================*/
void ContextData::setWpHighATrue(){highA = true;}
void ContextData::setWpHighAFalse(){highA = false;}
void ContextData::setWpDrillingATrue(){drillingA = true;}
void ContextData::setWpDrillingAFalse(){drillingA = false;}
void ContextData::setWpIsMetalATrue(){isMetalA = true;}
void ContextData::setWpIsMetalAFalse(){isMetalC = false;}
/*================Setter for WP B================*/
void ContextData::setWpHighBTrue(){highB = true;}
void ContextData::setWpHighBFalse(){highB = false;}
void ContextData::setWpDrillingBTrue(){drillingB = true;}
void ContextData::setWpDrillingBFalse(){drillingB = false;}
void ContextData::setWpIsMetalBTrue(){isMetalB = true;}
void ContextData::setWpIsMetalBFalse(){isMetalC = false;}
/*================Setter for WP C================*/
void ContextData::setWpHighCTrue(){highC = true;}
void ContextData::setWpHighCFalse(){highC = false;}
void ContextData::setWpDrillingCTrue(){drillingC = true;}
void ContextData::setWpDrillingCFalse(){drillingC = false;}
void ContextData::setWpIsMetalCTrue(){isMetalC = true;}
void ContextData::setWpIsMetalCFalse(){isMetalC = false;}

/*================Load workpieces from JSON================*/
void ContextData::setLoadConfig(){
    std::string wpDataDir = "wp_cfg.json";
    std::ifstream wpCfg(wpDataDir);

    json dataJson = json::parse(wpCfg);

    // read json object
    if (dataJson.is_object()) 
    {
        auto obj = dataJson.get<json::object_t>();

        // Built a json obj for all three work pieces  -> for example TypeA: 'TypeA:{"drilling":true,"high":true,"isMetal":true}'
        for (auto& wpType : obj)
        {
            //print put the json file for each type
            //std::cout << wpType.first << ":\n\t" << wpType.second << "\n";

            // read the json file for each workpiece type
            if (wpType.second.is_object())
            {
                auto obj2 = wpType.second.get<json::object_t>();
                //read the boolean from high, drilling, isMetal
                for (auto& wpData : obj2)
                {
                    //print the boolean for each key in the current workpiece type 
                    //std::cout << wpData.first << ": " << wpData.second << "\n";

                    if (wpType.first == "TypeA") 
                    {
                        if (wpData.first == "high")
                        {
                            wpData.second == "true" ? setWpHighATrue() : setWpHighAFalse();
                        } 
                        else if (wpData.first == "drilling") 
                        {
                            wpData.second == "true" ? setWpDrillingATrue() : setWpDrillingAFalse();
                        } 
                        else if (wpData.first == "isMetal") 
                        {
                            wpData.second == "true" ? setWpIsMetalATrue() : setWpIsMetalAFalse();
                        }
                        else 
                        {
                            std::cout << "Wrong keys for TypeA workpieces were found. Correct keys for workpiece data are 'high', 'drilling' and 'isMetal'.\n" << "Please check the JSON file." << std::endl;
                        }
                    } 
                    else if (wpType.first == "TypeB") 
                    {
                        if (wpData.first == "high")
                        {
                            wpData.second == "true" ? setWpHighBTrue() : setWpHighBFalse();
                        } 
                        else if (wpData.first == "drilling") 
                        {
                            wpData.second == "true" ? setWpDrillingBTrue() : setWpDrillingBFalse();
                        } 
                        else if (wpData.first == "isMetal") 
                        {
                            wpData.second == "true" ? setWpIsMetalBTrue() : setWpIsMetalBFalse();
                        }
                        else 
                        {
                            std::cout << "Wrong keys for TypeB workpieces were found. Correct keys for workpiece data are 'high', 'drilling' and 'isMetal'.\n" << "Please check the JSON file." << std::endl;
                        }
                    } 
                    else if (wpType.first == "TypeC") 
                    {
                        if (wpData.first == "high")
                        {
                            wpData.second == "true" ? setWpHighCTrue() : setWpHighCFalse();
                        } 
                        else if (wpData.first == "drilling") 
                        {
                            wpData.second == "true" ? setWpDrillingCTrue() : setWpDrillingCFalse();
                        } 
                        else if (wpData.first == "isMetal") 
                        {
                            wpData.second == "true" ? setWpIsMetalCTrue() : setWpIsMetalCFalse();
                        }
                        else 
                        {
                            std::cout << "Wrong keys for TypeC workpieces were found. Correct keys for workpiece data are 'high', 'drilling' and 'isMetal'.\n" << "Please check the JSON file." << std::endl;
                        }
                    }
                    else 
                    {
                        std::cout << "Wrong key for workpieces found. Correct keys for workpieces are 'TypeA', 'TypeB' and 'TypeC'.\n" << "Please check the JSON file." << std::endl;
                    }
                }
            }
        }
    }

    setLoadedConfTrue();
    
    //Print all json keys (hight, drilling, isMetal) for all workpiece types
    std::cout << "\tHigh TypeA:\t\t" << getWpHighA() <<std::endl;
    std::cout << "\tDrilling TypeA:\t\t" << getWpDrillingA() <<std::endl;
    std::cout << "\tMetal TypeA:\t\t" << getWpIsMetalA() <<std::endl;
    std::cout << "\tHigh TypeB:\t\t" << getWpHighB() <<std::endl;
    std::cout << "\tDrilling TypeB:\t\t" << getWpDrillingB() <<std::endl;
    std::cout << "\tMetal TypeB:\t\t" << getWpIsMetalB() <<std::endl;
    std::cout << "\tHigh TypeC:\t\t" << getWpHighC() <<std::endl;
    std::cout << "\tDrilling TypeC:\t\t" << getWpDrillingC() <<std::endl;
    std::cout << "\tMetal TypeC:\t\t" << getWpIsMetalC() <<std::endl;
  
}

//Getter for WP A
int ContextData::getWpHighA(){return highA;}
int ContextData::getWpDrillingA(){return drillingA;}
int ContextData::getWpIsMetalA(){return isMetalA;}
//Getter for WP B
int ContextData::getWpHighB(){return highB;}
int ContextData::getWpDrillingB(){return drillingB;}
int ContextData::getWpIsMetalB(){return isMetalB;}
//Getter for WP C
int ContextData::getWpHighC(){return highC;}
int ContextData::getWpDrillingC(){return drillingC;}
int ContextData::getWpIsMetalC(){return isMetalC;}
