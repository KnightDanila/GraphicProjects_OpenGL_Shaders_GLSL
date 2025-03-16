// Made by pattern Singleton
// Adds Interface than Interface <- Options
class Options {
private:
	Options() {
		width = 640;
		height = 480;
		frequency = 60;
	}
	~Options() {
		delete _instance;
	}
	static Options* _instance;

public:
	static Options* getInstance() {
		if (_instance == nullptr) {
			_instance = new Options();
		}
		return _instance;
	}

	// Window parameters
	int width;
	int height;
	int frequency;
};
Options* Options::_instance = nullptr;



	Options* option1 = Options::getInstance();
	Options::_instance = nullptr;
	println(option1->width, option1->height, option1->frequency);

	Options* option2 = Options::getInstance();
	option2->width = 1920;
	option2->height = 1080;
	println(option1->width, option1->height, option1->frequency);
	println(option2->width, option2->height, option2->frequency);