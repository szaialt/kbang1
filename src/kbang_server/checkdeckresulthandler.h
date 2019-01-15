#ifndef CHECKDECKRESULTHANDLER_H
#define CHECKDECKRESULTHANDLER_H

class CheckDeckResultHandler
{
public:
    virtual ~CheckDeckResultHandler() {}
    virtual void checkResult(bool result) = 0;
    inline int PredrawCheck() const { return m_PredrawCheck; }
protected:
    int m_PredrawCheck;
}; 

#endif // CHECKDECKRESULTHANDLER_H
