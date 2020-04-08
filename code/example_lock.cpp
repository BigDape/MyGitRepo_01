class CritSect
{
	friend class Lock;
public:
	CritSect() { /*InitializeCriticalSection(&_critSection); */}
	~CritSect() { /*DeleteCriticalSection(&_critSection);*/ }
private:
	void Acquire()
	{
		/*EnterCriticalSection(&_critSection);*/
	}
	void Release()
	{
		/*LeaveCriticalSection(&_critSection);*/
	}
protected:
	//CRIICAL_SECTION _critSection;

};

class Lock
{
public:
	Lock(CritSect& critSect) :_critSect(critSect)
	{

	}
};