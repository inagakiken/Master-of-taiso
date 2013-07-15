#include "StdAfx.h"
#include "InputModel.h"


InputModel::InputModel(void)
{
	//fileName = "a.txt";
}

InputModel::InputModel(std::string tempFileName)
{
	//fileName = tempFileName;
}

InputModel::~InputModel(void)
{
}

/*
void InputModel::changeFile(std::string tempFileName)
{
	fileName = tempFileName;
}
*/

void InputModel::readFile(std::string tempFileName)
{
	std::ifstream ifs( tempFileName );
	if (!ifs) {
		std::cout << "***error  入力ファイルを開けません\n";
		return;
	}

	float x, y, z;

	while (!ifs.eof()) {
		Skeleton* skeleton = new Skeleton();
		for(int i = 0 ; i < 15 ; i++){
			ifs >> x >> y >> z;
			nite::Point3f pos;
			pos.set(x,y,z);
			skeleton->setJointPosition( i, pos);
			
		}
		model.push_back(*skeleton);
	}
	ifs.close();

}

void InputModel::writeFile(std::string tempFileName, Skeleton** skeleton)
{
	std::ofstream ofs( tempFileName );
}



