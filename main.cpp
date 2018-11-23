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
int multOperation(int a,int b)
{
    return a*b;
}


void printBinary(string a,int b, int c, int d)
{
    bitset<5> BinaryStore(d);
    bitset<5> BinaryRs(b);
    bitset<5> BinaryRt(c);
    cout<<a<<" "<<BinaryRs<<" "<<BinaryRt<<" "<<BinaryStore<<endl;
    cout<<endl;

}

int main()
{
    std::vector<std::string> memo;
    std::vector<std::string> word;
    std::vector<std::string> reg;
    string testline;
    string tempStorage;
    int temp[4];
    string add = "ADD";
    string sub = "SUB";
    string mult = "MULT";
    string lw = "lw";
    string tempString[20];
    string opCode;
    int store,locate;


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
    ifstream memory("memory.txt");
    if (!memory)
    {
        cout << "There was an error opening the file.\n";
        return 0;
    }

    while( memory>>testline )
    {
        memo.push_back(testline);
    }



    for (int i=0; i<word.size(); i++)
    {


        if(word[i]==add)
        {
            cout<<word[i]<<" "<<word[i+1]<<" , "<<word[i+2]<<" , "<<word[i+3]<<endl;
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
                else if(temp[j-2]!=0)
                {
                    tempString[j-2]=word[i+j];
                }


            }

            for (int i=0; i<reg.size(); i++)
            {
                if(temp[0]==0 || temp[1]==0 )
                {
                    if(reg[i]==tempString[0] && reg[i]==tempString[1])
                    {
                        string s = reg[i+1];
                        stringstream value(s);
                        int tempReg = 0;
                        value >> tempReg;
                        temp[0]=tempReg;
                        temp[1]=tempReg;


                    }
                    else if(reg[i] == tempString[0])
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
            cout<<word[i]<<" "<<word[i+1]<<" , "<<word[i+2]<<" , "<<word[i+3]<<endl;

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
                else if(temp[j-2]!=0)
                {
                    tempString[j-2]=word[i+j];
                }

            }

            for (int i=0; i<reg.size(); i++)
            {
                if(temp[0]==0 || temp[1]==0 )
                {
                    if(reg[i]==tempString[0] && reg[i]==tempString[1])
                    {
                        string s = reg[i+1];
                        stringstream value(s);
                        int tempReg = 0;
                        value >> tempReg;
                        temp[0]=tempReg;
                        temp[1]=tempReg;


                    }

                    else if(reg[i] == tempString[0])
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
        else if(word[i]==mult)
        {
            cout<<word[i]<<" "<<word[i+1]<<" , "<<word[i+2]<<" , "<<word[i+3]<<endl;

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
                else if(temp[j-2]!=0)
                {
                    tempString[j-2]=word[i+j];
                }

            }

            for (int i=0; i<reg.size(); i++)
            {
                if(temp[0]==0 || temp[1]==0 )
                {
                    if(reg[i]==tempString[0] && reg[i]==tempString[1])
                    {
                        string s = reg[i+1];
                        stringstream value(s);
                        int tempReg = 0;
                        value >> tempReg;
                        temp[0]=tempReg;
                        temp[1]=tempReg;


                    }

                    else if(reg[i] == tempString[0])
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
                }

                else if
                (reg[i] == mult)
                {

                    opCode = reg[i+1];
                }



            }


            int multiplied = multOperation(temp[0],temp[1]);
            printBinary(opCode,temp[0],temp[1],multiplied);
        }
        else if(word[i]==lw)
        {
            cout<<word[i]<<" "<<word[i+1]<<" , "<<word[i+2]<<" , "<<word[i+3]<<endl;

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
                else if(temp[j-2]!=0)
                {
                    tempString[j-2]=word[i+j];
                }

            }

            for (int i=0; i<reg.size(); i++)
            {

                if
                (reg[i] == tempString[1])
                {
                    string s = reg[i+1];
                    stringstream value(s);
                    int tempReg = 0;
                    value >> tempReg;
                    temp[1]=tempReg;
                    if(temp[1]==0)
                    {
                        for(int i=0; i<=memo.size(); i++)
                        {
                            if(memo[i]==s)
                            {
                                string s = memo[i+1];
                                stringstream value(s);
                                int tempReg = 0;
                                value >> tempReg;
                                temp[1]=tempReg;
                                int locate = i+1 + (temp[0]*2);
                                string t = memo[locate];
                                stringstream value2(t);
                                int tempLocate = 0;
                                value2 >> tempLocate;
                                temp[2]=tempLocate;
                            }

                        }
                    }
                    else
                    {
                        temp[1]=tempReg;
                    }

                }


                else if
                (reg[i] == lw)
                {

                    opCode = reg[i+1];
                }

            }
            printBinary(opCode,temp[0],temp[1],temp[2]);
        }

    }
    memory.close();
    registers.close();
    assemblyCode.close();


}
