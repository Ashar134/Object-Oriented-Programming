#include <iostream>
using namespace std;

class Animal              ///Animal Class
{
protected:
    string name;
    int age;
    string specie;

public:
    void setName(string name) // Setter Functions
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setSpecie(string specie)
    {
        this->specie = specie;
    }

    string getName() // Getter Functions
    {
        return this->name;
    }

    int getAge()
    {
        return this->age;
    }

    string getSpecie()
    {
        return this->specie;
    }

    void Animaldisplay() // Method
    {
        cout << "Name : " << getName() << endl;
        cout << "Age :" << getAge() << endl;
        cout << "Specie :" << getSpecie() << endl;
    }
};

class Mammal : public Animal         //Mammal Class
{
protected:
    string furcolor;
    string hungerlevel;
    char groomed;

public:
    void setFurColor(string furcolor) // Setter Functions
    {
        this->furcolor = furcolor;
    }

    void setHungerlevel(string hungerlevel)
    {
        this->hungerlevel = hungerlevel;
    }

    void setGroomed(char groomed)
    {
        this->groomed = groomed;
    }

    string getFurColor() // Setter Function
    {
        return this->furcolor;
    }

    string getHungerlevel()
    {
        return this->hungerlevel;
    }

    char getGroomed()
    {
        return this->groomed;
    }

    void DisplayFurColor()       // Methods
    {
        cout << "Color is : " << getFurColor();
    }
    void DisplayHungerlevel()
    {
        cout << "Hunger Level : " << getHungerlevel();
    }
    void DisplayGroomed()
    {
        if (getGroomed() == 'y' || getGroomed() == 'Y')
        {
            cout << "No Grooming Required" << endl;
        }
        else
        {
            cout << "Yes Grooming Required" << endl;
        }
    }
};

class Bird : public Animal // Bird Class
{
protected:
    string featherColor;
    string nestLocation;
    string foodPreference;

public:
    void setFeatherColor(string featherColor) // Setter Function
    {
        this->featherColor = featherColor;
    }

    void setNestLocation(string nestLocation)
    {
        this->nestLocation = nestLocation;
    }

    void setFoodPreference(string foodPreference)
    {
        this->foodPreference = foodPreference;
    }

    string getFeatherColor() // Getter Function
    {
        return this->featherColor;
    }

    string getNestLocation()
    {
        return this->nestLocation;
    }

    string getFoodPreference()
    {
        return this->foodPreference;
    }

    void DisplayfeatherColor() // Methods
    {
        cout << "Feather Color : " << getFeatherColor() << endl;
    }
    void DisplaynestLocation()
    {
        cout << "Nest Location : " << getNestLocation() << endl;
    }
    void DisplayfoodPreference()
    {
        cout << "Food Preference : " << getFoodPreference() << endl;
    }
};

class Reptile : public Animal // Reptile Class
{
protected:
    string scalePattern;
    int sunbathingDuration;
    string habitat;

public:
    void setScalePattern(string scalePattern) // Setter Function
    {
        this->scalePattern = scalePattern;
    }

    void setSunbathingDuration(int sunbathingDuration)
    {
        this->sunbathingDuration = sunbathingDuration;
    }

    void setHabitat(string habitat)
    {
        this->habitat = habitat;
    }

    string getScalePattern() // Getter Function
    {
        return this->scalePattern;
    }

    int getSunbathingDuration()
    {
        return this->sunbathingDuration;
    }

    string getHabitat()
    {
        return this->habitat;
    }

    void const DisplayScalePattern() //......Methods
    {
        cout << "Scale Pattern : " << getScalePattern() << endl;
    }

    void const DisplaySunBathingDuration()
    {
        cout << "Duration : " << getSunbathingDuration() << endl;
    }

    void const Displayhabitat()
    {
        cout << "Habitat : " << getHabitat() << endl;
    }
};

int main()
{
    int choice;
    int choice1, choice2;
    string food;
    string updateLocation;
    char grooming;
    int playtime;
    int updateTime;

    Mammal kangaroo, lion;

    kangaroo.setName("Kangaroo");
    kangaroo.setAge(5);
    kangaroo.setSpecie("Red Kangaroo");
    kangaroo.setFurColor("Dark brown");
    kangaroo.setHungerlevel("Low");
    kangaroo.setGroomed('y');

    lion.setName("Lion");
    lion.setAge(4);
    lion.setSpecie("African Lion");
    lion.setFurColor("Light Brown");
    lion.setHungerlevel("High");
    lion.setGroomed('n');

    Bird eagle;
    eagle.setName("Eagle");
    eagle.setAge(3);
    eagle.setSpecie("Bald Eagle");
    eagle.setFeatherColor("Brown");
    eagle.setNestLocation("High in the mountains");
    eagle.setFoodPreference("Fish");

    Reptile turtle;
    turtle.setName("Turtle");
    turtle.setAge(8);
    turtle.setSpecie("Box Turtle");
    turtle.setScalePattern("Brown");
    turtle.setSunbathingDuration(2);
    turtle.setHabitat("Forests");

    cout << "WELCOME TO ZOO" << endl;
    cout << "-------------------" << endl;
    cout << "Kangroo\t Lion" << endl;
    cout << "Eagle \t Turtle" << endl;
    cout << "-------------------" << endl;

    do
    {

        cout << "PRESS 1. Display Animal Information" << endl;
        cout << "PRESS 2. Feed the Animals" << endl;
        cout << "PRESS 3. Update the Behavior" << endl;
        cout << "PRESS 4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            kangaroo.Animaldisplay();
            kangaroo.DisplayFurColor();
            kangaroo.DisplayHungerlevel();
            kangaroo.DisplayGroomed();
            cout << "------------------" << endl;
            lion.Animaldisplay();
            lion.DisplayFurColor();
            lion.DisplayHungerlevel();
            lion.DisplayGroomed();
            cout << "------------------" << endl;
            eagle.Animaldisplay();
            eagle.DisplayfeatherColor();
            eagle.DisplaynestLocation();
            eagle.DisplayfoodPreference();
            cout << "------------------" << endl;
            turtle.Animaldisplay();
            turtle.DisplayScalePattern();
            turtle.DisplaySunBathingDuration();
            turtle.Displayhabitat();
            cout << "------------------" << endl;

            break;
        case 2:
            cout << "Meal Available" << endl;
            cout << "Mammal ->\t  banana\t apple\t mango \t meat\t beaf \tgrass" << endl;
            cout << "Birds  ->\t  fish\t  worm\t pear\t apple" << endl;
            cout << "Reptile->\t  pears\t grass " << endl;

            cout << "Enter the animal (1 - Kangaroo, 2 - Lion, 3 - Eagle, 4 - Turtle): ";
            cin >> choice1;
            cout << "Enter the food to feed: ";
            cin >> food;

            switch (choice1)
            {
            case 1:
                if (food == "banana" || food == "apple" || food == "mango" || food == "grass")
                {
                    cout << "Kangaroo enjoys the fruits." << endl;
                }
                else
                {
                    cout << "Kangaroo doesn't like this food." << endl;
                }
                break;

            case 2:
                if (food == "meat" || food == "beaf")
                {
                    cout << "Lion loves the food." << endl;
                }
                else
                {
                    cout << "Lion is not interested in this food." << endl;
                }
                break;

            case 3:
                if (food == "fish" || food == "worm" || food == "apple" || food == "pear")
                {
                    cout << "Eagle like the food ." << endl;
                }
                else
                {
                    cout << "Eagle doesn't eat that." << endl;
                }
                break;

            case 4:
                if (food == "insect" || food == "pears" || food == "grass")
                {
                    cout << "Turtle happily eats food." << endl;
                }
                else
                {
                    cout << "Turtle has no interest in this food." << endl;
                }
                break;
            }
            break;
        case 3:

            cout << "Enter the Animal type you want to Update :";
            cin >> choice2;

            if (choice2 == 1)
            {
                cout << "Grooming Required Press y:";
                cin >> grooming;
                kangaroo.setGroomed(grooming);
                cout << "Enter play time :";
                cin >> playtime;

                cout << "Play time : " << playtime << endl;
            }
            else if (choice2 == 2)
            {
                cout << "Enter to update the location : ";
                cin >> updateLocation;
                eagle.setNestLocation(updateLocation);
            }
            else if (choice2 == 3)
            {
                cout << "Enter to Update the SunBath Timing :";
                cin >> updateTime;
                turtle.setSunbathingDuration(updateTime);
            }
        }

    } while (choice != 4);

    return 0;
}
