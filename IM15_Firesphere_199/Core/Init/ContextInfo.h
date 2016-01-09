namespace Core{

	//OpenGL versions
	//structure for storing opengl context
	struct ContextInfo
	{
		int major_version, minor_version;
		bool core;

		ContextInfo()//default
		{
			major_version = 3;
			minor_version = 3;
			core = true;
		}

		ContextInfo(int major_version, int minor_version, bool core)
		{
			this->major_version = major_version;
			this->minor_version = minor_version;
			this->core = core;
		}
	};
}