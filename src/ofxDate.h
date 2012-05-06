#ifndef OFXDATE_H
#define OFXDATE_H


class ofxDate
{
    public:
        ofxDate();
        ofxDate(int year, int month, int day);
        virtual ~ofxDate();
        unsigned int getDay() { return m_day; }
        void setDay(unsigned int day) { m_day = day; }
        unsigned int getMonth() { return m_month; }
        void setMonth(unsigned int month) { m_month = month; }
        unsigned int getYear() { return m_year; }
        void setYear(unsigned int year) { m_year = year; }
        bool isLeapyear()
        {
            if(m_year<1) {
		// ofLogError() << "isLeapyear of " << m_year;
		return false;
            }
	    if(m_year%4) return false;
            if(m_year<=1582) return true;
            if(m_year%100) return true;
            if(m_year%400) return false;
            return true;
        }
        int daysPerMonth()
        {
            switch(m_month) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    return 31;
                case 4:
                case 6:
                case 9:
                case 11:
                    return 30;
                case 2: return (28 + isLeapyear());
                default:
		  // ofLogError() << "daysPerMonth";
			return -1;
            }
        }
        int getCalendarWeek() const
        {
            // ...
        }
    protected:
    private:
        unsigned int m_day;
        unsigned int m_month;
        unsigned int m_year;
};

#endif

