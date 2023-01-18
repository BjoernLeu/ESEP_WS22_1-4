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
void ContextData::setLoadedConfFalse(){loadedConf = false;}
void ContextData::setLoadedConfTrue(){loadedConf = true;}
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
void ContextData::incWpCount(){wpCount++;}
void ContextData::decWpCount(){wpCount--;}
int ContextData::getWpCount(){return wpCount;}

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

/*================Workpiece List C================*/
//get number of workpieces on the belt
int ContextData::getNumberWpsOnBelt(){
    std::cout << "wpList.size: " <<wpList.size() << std::endl;
    return wpList.size();}

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
  
  setAddExpectedWorkpiece(getWpHighA(), getWpDrillingA(), getWpIsMetalA());
  setAddExpectedWorkpiece(getWpHighB(), getWpDrillingB(), getWpIsMetalB());
  setAddExpectedWorkpiece(getWpHighC(), getWpDrillingC(), getWpIsMetalC());
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

/*================Timer WP-Tracking================*/
void ContextData::setTime_lbI_fast_max(){lbI_fast_max = std::chrono::system_clock::now();}
void ContextData::setTime_hsWP_fast_max(){hsWP_fast_max = std::chrono::system_clock::now();}
void ContextData::setTime_lbSW_fast_max(){lbSW_fast_max = std::chrono::system_clock::now();}
void ContextData::setTime_lbO_fast_max(){lbO_fast_max = std::chrono::system_clock::now();}

void ContextData::setTime_lbI_fast_min(){lbI_fast_min = std::chrono::system_clock::now();}
void ContextData::setTime_hsWP_fast_min(){hsWP_fast_min = std::chrono::system_clock::now();}
void ContextData::setTime_lbSW_fast_min(){lbSW_fast_min = std::chrono::system_clock::now();}
void ContextData::setTime_lbO_fast_min(){lbO_fast_min = std::chrono::system_clock::now();}

void ContextData::setTime_lbI_slow(){lbI_slow_max = std::chrono::system_clock::now();}
void ContextData::setTime_hsWP_slow(){hsWP_slow_max = std::chrono::system_clock::now();}

void ContextData::setSectorDiff_max()
{
    s1_length_max = hsWP_fast_max - lbI_fast_max;
    s2_length_max = lbSW_fast_max - hsWP_fast_max;
    s3_length_max = lbO_fast_max - lbSW_fast_max;
}
void ContextData::setSectorDiff_min()
{
    s1_length_min = hsWP_fast_min - lbI_fast_min;
    s2_length_min = lbSW_fast_min - hsWP_fast_min;
    s3_length_min = lbO_fast_min - lbSW_fast_min;
    segmentDistanceList[0] = std::chrono::duration<double>(s1_length_min).count();
    segmentDistanceList[1] = std::chrono::duration<double>(s1_length_max + s2_length_min).count();
    segmentDistanceList[2] = std::chrono::duration<double>(s1_length_max + s2_length_min + s3_length_min).count();
}

double ContextData::getS1Max(){return std::chrono::duration<double>(s1_length_max).count();}
double ContextData::getS2Max(){return std::chrono::duration<double>(s2_length_max).count();}
double ContextData::getS3Max(){return std::chrono::duration<double>(s3_length_max).count();}

double ContextData::getS1Min(){return std::chrono::duration<double>(s1_length_min).count();}
double ContextData::getS2Min(){return std::chrono::duration<double>(s2_length_min).count();}
double ContextData::getS3Min(){return std::chrono::duration<double>(s3_length_min).count();}

void ContextData::setSlowDur(){slowDur = hsWP_slow_max-lbI_slow_max;}
double ContextData::getSlowDur(){return std::chrono::duration<double>(slowDur).count();}

void ContextData::setSlowFactor(){slowFactor = s1_length_min / slowDur;}
 /**
  * @brief Calculates the Factor for the difference between fast and slow. 
  * 
  * @return double The Slowfactor
  */
double ContextData::getSlowFactor(){return slowFactor;}

/*================WP================*/

/* 
    struct workpiece {
        int id;
        int type;
        bool metal;
        float height;
        bool flipped;
        int segment;
        double distance;
    };
*/

void ContextData::addWp(int type, bool metal, float height, bool flipped, int segment, double distance) {
    std::rotate(wpList.begin(), wpList.end(), wpList.end());
	wpList.push_back({getWpCount(), type, metal, height, flipped, segment, distance});
	std::cout << "WS added" << std::endl;
    std::rotate(wpList.begin(), wpList.end(), wpList.end());
//    std::cout << wpList <<std::endl;
}
void ContextData::popWp() {
    if(wpList.size() > 1){
        for(std::vector<workpiece>::iterator it = wpList.begin(); it != wpList.end(); ++it) {
            if((*it).segment == 3 && (*it).distance > (*it).distance){
                wpList.erase(it);
            }
        }
    } else {
        wpList.pop_back();
    }
}
workpiece ContextData::getWp() {return wpList.back();}
bool ContextData::getWpEmpty() {return wpList.empty();}

void ContextData::addWpMetal() {
    if(wpList.size() > 1){
        for (int i = 1; i < wpList.size()-1; i++){
            if(wpList[i].segment == 3 && wpList[i].distance > wpList[i+1].distance){
                wpList[i].metal = true;
                break;
            }
        }
    } else {
        wpList[0].metal = true;
    }
}

bool ContextData::getWpMetal(){
	if(wpList.size() > 1){
        std::cout << "addWpType: wpList.size > 0" << std::endl;
        for (int i = 1; i < wpList.size()-1; i++){
            if(wpList[i].segment == 3 && wpList[i].distance > wpList[i+1].distance && wpList[i-1].segment == 2){        
                std::cout << "addWpType: " << wpList[i].type << std::endl;
                return wpList[i].metal;
            }
        }
    } else {
        std::cout << "addWpType: wpList.size <= 1" << std::endl;
        std::cout << "addWpType: " << wpList[0].type << std::endl;
        return wpList[0].metal;
    }
}


void ContextData::addWpType(int type, int height){
    std::cout << "wpList.size: " <<wpList.size() << std::endl;
    if(wpList.size() > 1){
        std::cout << "addWpType: wpList.size > 0" << std::endl;
        for (int i = 1; i < wpList.size()-1; i++){
            if(wpList[i].segment == 1 && wpList[i].type == -1){
                wpList[i].type = type;
                wpList[i].height = height;
                break;
            }
        }
    } else {
        std::cout << "addWpType: wpList.size <= 1" << std::endl;
        wpList[0].type = type;
        wpList[0].height = height;
    }
}
 /**
  * @brief Returns the Wp Type of the Wp in lbSW
  * 
  * @return int WP_DRILLING = 55, WP_FLAT = 56, WP_HIGH = 57, WP_CODE = 59
  */
int ContextData::getWpType(){
    if(wpList.size() > 1){
        std::cout << "getWpType: wpList.size > 0" << std::endl;
        for (int i = 1; i < wpList.size()-1; i++){
            if(wpList[i].segment == 3 && wpList[i].distance > wpList[i+1].distance && wpList[i-1].segment == 2){        
                std::cout << "getWpType: " << wpList[i].type << std::endl;
                return wpList[i].type;
            }
        }
    } else {
        std::cout << "getWpType: wpList.size <= 1" << std::endl;
        std::cout << "getWpType: " << wpList[0].type << std::endl;
        return wpList[0].type;
    }
}

void ContextData::addFlipped(){
    wpList.back().flipped = true;
}

void ContextData::changeSeg2(){
    if(wpList.size() > 1){
        std::cout << "changeSeg2: wpList.size > 0" << std::endl;
        for (int i = 0; i < wpList.size()-1; i++){
            if(wpList[i].segment == 1 && wpList.size() == i+1){
                std::cout << "changeSeg2 letztes aus Liste" << std::endl;
                wpList[0].segment = 2;
            } else if(wpList[i].segment == 1 && wpList[i+1].segment >= 2){        
                std::cout << "changeSeg2 anderes schon in seg2" << std::endl;
                wpList[0].segment = 2;
            }
        }
    } else {
        std::cout << "changeSeg2 nur eins in Liste" << std::endl;
        wpList[0].segment = 2;
    }
}

void ContextData::changeSeg3(){
    if(wpList.size() > 1){
        std::cout << "changeSeg3: wpList.size > 0" << std::endl;
        for (int i = 0; i < wpList.size()-1; i++){
            if(wpList[i].segment == 2 && wpList.size() == i+1){
                std::cout << "changeSeg3 letztes aus Liste" << std::endl;
                wpList[0].segment = 3;
            } else if(wpList[i].segment == 2 && wpList[i+1].segment >= 3){        
                std::cout << "changeSeg3 anderes schon in seg2" << std::endl;
                wpList[0].segment = 3;
            }
        }
    } else {
        std::cout << "changeSeg3 nur eins in Liste" << std::endl;
        wpList[0].segment = 3;
    }
}
/// @brief Add a new workpiece in the list of expected workpieces
/// @param height height workpiece 
/// @param metal workpiece with metal
/// @param isDrilling drilling in workpiece
void ContextData::setAddExpectedWorkpiece(bool height, bool isDrilling, bool metal) 
{
    wpExpList.push_back({height, metal, isDrilling});
}



/// @brief increase the global counter for expectedCount
void ContextData::increaseExpectedCount()
{
    if (expectedCount <= 2) 
    {
        expectedCount++;
    }
    else
    {
        expectedCount = 0;
    }
}





bool ContextData::getExpectedWpHeight(){return wpExpList[expectedCount].height;}
bool ContextData::getExpectedWpMetal(){return wpExpList[expectedCount].metal;}
bool ContextData::getExpectedWpIsDrilling(){return wpExpList[expectedCount].isDrilling;}
