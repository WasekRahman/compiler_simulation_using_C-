#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

int addOperation(int a, int b)
{
    return a+b;
}
int subOperation(int a,int b)
{
    return a-b;
}
int divOperation(int a,int b)
{
    return a/b;
}
int multOperation(int a,int b)
{
    return a*b;
}

void printBinary(string a,int b, int c, int d)
{
    bitset<2> BinaryStore(d);
    bitset<2> BinaryRs(b);
    bitset<2> BinaryRt(c);
    cout<<a<<" "<<BinaryRs<<" "<<BinaryRt<<" "<<BinaryStore<<endl;

}

int main()
{
    std::vector<std::string> vecOfStr;
    std::vector<std::string> word;
    std::vector<std::string> reg;
    string testline;
    string tempStorage;
    int temp[4];
    int temp1[4];
    string add = "ADD";
    string sub = "SUB";
    string tempString[20];
    string opCode;
    int store;

    ifstream assemblyCode ("instructions.txt" );

    if (!assemblyCode)
    {
        cout << "There was an error opening the file.\n";
        return 0;
    }

    while( assemblyCode>>testline )
        word.push_back(testline);

    for(std::vector<float>::size_type i = 0; i < word.size(); i++)
    {
        if(word[i]==",")
        {
            word.erase(word.begin()+i);
        }
    }
    ifstream registers("registers.txt");
    if (!registers)
    {
        cout << "There was an error opening the file.\n";
        return 0;
    }

    while( registers>>testline )
    {
        reg.push_back(testline);
    }



    for (int i=0; i<word.size(); i++)
    {


        if(word[i]==add)
        {
            tempStorage = word[i+1];
            for(int j=2; j<=3; j++)

            {
                string s = word[i+j];
                stringstream value(s);
                int tempValue = 0;
                value >> tempValue;
                temp[j-2]=tempValue;
                if(temp[j-2]==0)
                {
                    tempString[j-2] = word[i+j];

                }

            }

            for (int i=0; i<reg.size(); i++)
            {
                if(reg[i] == tempString[0])
                {

                    string s = reg[i+1];
                    stringstream value(s);
                    int tempReg = 0;
                    value >> tempReg;
                    temp[0]=tempReg;
                }

                else if
                (reg[i] == tempString[1])
                {

                    string s = reg[i+1];
                    stringstream value(s);
                    int tempReg = 0;
                    value >> tempReg;
                    temp[1]=tempReg;
                }
                else if (reg[i] == tempStorage)
                {
                    string s = reg[i+1];
                    stringstream value(s);
                    value >> store;

                }
                else if(reg[i] == add)
                {

                    opCode = reg[i+1];
                }

            }

            int added = addOperation(temp[0],temp[1]);
            printBinary(opCode,temp[0],temp[1],added);
        }


        else if(word[i]==sub)
        {

            tempStorage = word[i+1];
            for(int j=2; j<=3; j++)

            {
                string s = word[i+j];
                stringstream value(s);
                int tempValue = 0;
                value >> tempValue;
                temp[j-2]=tempValue;
                if(temp[j-2]==0)
                {
                    tempString[j-2] = word[i+j];

                }

            }

                for (int i=0; i<reg.size(); i++)
                    {
                        if(reg[i] == tempString[0])
                        {

                            string s = reg[i+1];
                            stringstream value(s);
                            int tempReg = 0;
                            value >> tempReg;
                            temp[0]=tempReg;
                        }
                        else if
                        (reg[i] == tempString[1])
                        {

                            string s = reg[i+1];
                            stringstream value(s);
                            int tempReg = 0;
                            value >> tempReg;
                            temp[1]=tempReg;
                        }
                        else if (reg[i] == tempStorage)
                        {
                            string s = reg[i+1];
                            stringstream value(s);
                            value >> store;

                        }
                        else if
                        (reg[i] == sub)
                        {

                            opCode = reg[i+1];
                        }



                }


            int subtracted = subOperation(temp[0],temp[1]);
            printBinary(opCode,temp[0],temp[1],subtracted);
        }
    }

    assemblyCode.close();


}
