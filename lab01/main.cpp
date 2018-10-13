#include <QCoreApplication>
#include <QString>
#include <QVector>
#include <qDebug>
typedef struct student//定义结构体 student,保证score,name,number在同一类下
{
    int score1;
    int score2;
    QString name;
    int number;
}student;


int com(const void *a, const void *b)//比较数据大小，确定排序位置
{

    student * aa;
    student * bb;
    aa = (student *)a;
    bb = (student *)b;
    return aa->score1 > bb->score1?1:-1;
}
bool comQt(student &a, student &b)//定义comQt为bool型，获取返回值
{
   if (a.score1 > b.score1)
   {
        return true;
   }
   else
   {
       return false;
   }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    student stu0;
    student stu1;
    student stu2;
    student stu3;
                        //定义四个学生的学号，姓名，课程一成绩，课程二成绩
    stu0.score1= 80;
    stu0.score2=72;
    stu0.number=1403130209;
    stu0.name = "鲁智深";

    stu1.score1 = 82;
    stu1.score2=76;
    stu1.number=1403140101;
    stu1.name = "林冲";

    stu2.score1 = 76;
    stu2.score2=85;
    stu2.number=1403140102;
    stu2.name = "宋江";

    stu3.score1 = 88;
    stu3.score2=80;
    stu3.number=1403140103;
    stu3.name = "武松";

    QVector<student> mQVec;//使用qvector存放数据

    mQVec.push_back((stu0));//在mQVec尾部添加一个stu0

    mQVec.push_back((stu1));

    mQVec.push_back((stu2));

    mQVec.push_back((stu3));



    qSort(mQVec.begin(), mQVec.end(),comQt);//排序

    QVector<student>::iterator it1;//遍历，对student
    qDebug()<<"以课程一成绩进行排序，降序"<<endl;

    for(it1 = mQVec.begin(); it1 != mQVec.end(); it1 ++)//for循环，按序输出
    {
        student stu = *it1;
       qDebug()<< stu.number<<stu.name <<stu.score1<<stu.score2<< endl;

    }



    return a.exec();
}
