#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofxDate date = ofxDate();
    m_month = date.getMonth();
    m_day = date.getDay();
    m_year = date.getYear();
}

//--------------------------------------------------------------
void testApp::update()
{
    // date.inspect();
    // selected month
    // ofLogVerbose() << "date.getMonth() : " << m_month;
    // ofLogVerbose() << "date.getWeekday() : " << m_day;
    // ofLogVerbose() << "date.getYear() : " << m_year;
    date.setMonth(m_month);
    date.setYear(m_year);
    date.setDay(m_day);

}

//--------------------------------------------------------------
void testApp::draw()
{
    // note: to draw a calendar the date object state changes
    date.setDay(1);
    int calweek = date.getCalendarWeek();
    // ofLogVerbose() << "date.getCalendarWeek() : " << calweek;
    date=date-date.getWeekday();
    int dayNum=0;
    int dayX=96;
    int dayY=96;
    int dayR=64;
    int dayH=72;
    do {
        ofSetHexColor(0x2200FF);
        ofDrawBitmapString(ofToString(calweek), 5, dayY);
        for (dayNum=0; dayNum < 7; dayNum++, date=date+1) {
            if (date.getMonth() == m_month) {
                ofSetHexColor(0xFF4488);
            } else {
                ofSetHexColor(0x5599FF);
            }
            dayX = (dayNum * (dayR*2)) + (dayR*2);
            ofCircle(dayX, dayY, dayR);
            ofSetHexColor(0xDDEEFF);
            ofDrawBitmapString(ofToString(date.getDay())+"."+ofToString(date.getMonth())+"."+ofToString(date.getYear()), dayX-(dayR/2), dayY);
        }
        dayY += dayH;
        calweek++;
   }  while (date.getMonth() == m_month);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
