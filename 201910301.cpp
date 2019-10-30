//Singleton mode


#include<iostream>
using namespace std;


//realization one : Starving model
class starv
{
	static starv m_instance;
	starv()//Constrct function privatization go guarantee single instance
	{
		cout << "starv( )" << endl;
	}

	//prevent copy
	starv(const starv&);// starv(const starv&) = delete;
	starv operator=(const starv&);// starv operator=(const starv&) = delete;
public:
	static starv* GetStarc()
	{
		return &m_instance;
	}
};
starv starv::m_instance;//Create a instance before program operation

int main()
{
	starv::GetStarc();
	system("pause");
	return 0;
}


//realization two : slacker mode

#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

class slacker
{
	slacker()//Constrct function privatization go guarantee single instance
	{
		cout << "slacker( )" << endl;
	}

	//prevent copy
	slacker (const slacker&);// starv(const starv&) = delete;
	slacker operator=(const slacker&);// starv operator=(const starv&) = delete;

	static slacker* instance;//unique instance
	static mutex m_mtx;

public:

	static slacker* GetObject()
	{
		if (instance == nullptr)
		{
			m_mtx.lock();//add lock
			if (instance == nullptr)
			{
				instance = new slacker;
			}
			m_mtx.unlock();//remove lock
		}
		return instance;
	}
	class deconstruction//deconstruction in the way of inner class to prevent repeated deconstructions
	{
	public:
		~deconstruction()
		{
			if (instance)
			{
				cout << "deconstruction" << endl;
				delete instance;
				instance = nullptr;
			}
		}
	};

};

slacker* slacker::instance = nullptr;
mutex slacker::m_mtx;

int main()
{
	slacker::GetObject();
	slacker::deconstruction();
	system("pause");
	return 0;
}