#include <stdlib.h>

int main(int argc, char** argv) {

	system("ls -R ~/");

	return 0;
}


//Dir dir("/") ;
//Dir::iterator dit = dir.it();
//for (dit = it.begin(); dit != it.end(); it.next())
//{
//	print (*it);
//}

// Recurssion
#if 0
rec_dir_list(Dir::iterator dit) {
	static std::vector<string> v;
	for (dit = it.begin(); dit != it.end(); it.next())
	{
		if(*it).isDir() {
			rec_dir_list(it);
		} else {
			v.push_back(*it);
		}
	}
	return v;

}
#endif

#if 0
QDirIterator it(dir, QStringList() << "*.jpg", QDir::Files, QDirIterator::Subdirectories);
while (it.hasNext())
    qDebug() << it.next();
#endif