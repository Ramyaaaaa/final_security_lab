// C++ program to illustrate Rail Fence Cipher 
// Encryption and Decryption 
/*#include <bits/stdc++.h> 
using namespace std; 

// function to encrypt a message 
string encryptRailFence(string text, int key) 
{ 
	// create the matrix to cipher plain text 
	// key = rows , length(text) = columns 
	char rail[key][(text.length())]; 

	// filling the rail matrix to distinguish filled 
	// spaces from blank ones 
	for (int i=0; i < key; i++) 
		for (int j = 0; j < text.length(); j++) 
			rail[i][j] = '\n'; 

	// to find the direction 
	bool dir_down = false; 
	int row = 0, col = 0; 

	for (int i=0; i < text.length(); i++) 
	{ 
		// check the direction of flow 
		// reverse the direction if we've just 
		// filled the top or bottom rail 
		if (row == 0 || row == key-1) 
			dir_down = !dir_down; 

		// fill the corresponding alphabet 
		rail[row][col++] = text[i]; 

		// find the next row using direction flag 
		dir_down?row++ : row--; 
	} 

	//now we can construct the cipher using the rail matrix 
	string result; 
	for (int i=0; i < key; i++) 
		for (int j=0; j < text.length(); j++) 
			if (rail[i][j]!='\n') 
				result.push_back(rail[i][j]); 

	return result; 
} 

// This function receives cipher-text and key 
// and returns the original text after decryption 
string decryptRailFence(string cipher, int key) 
{ 
	// create the matrix to cipher plain text 
	// key = rows , length(text) = columns 
	char rail[key][cipher.length()]; 

	// filling the rail matrix to distinguish filled 
	// spaces from blank ones 
	for (int i=0; i < key; i++) 
		for (int j=0; j < cipher.length(); j++) 
			rail[i][j] = '\n'; 

	// to find the direction 
	bool dir_down; 

	int row = 0, col = 0; 

	// mark the places with '*' 
	for (int i=0; i < cipher.length(); i++) 
	{ 
		// check the direction of flow 
		if (row == 0) 
			dir_down = true; 
		if (row == key-1) 
			dir_down = false; 

		// place the marker 
		rail[row][col++] = '*'; 

		// find the next row using direction flag 
		dir_down?row++ : row--; 
	} 

	// now we can construct the fill the rail matrix 
	int index = 0; 
	for (int i=0; i<key; i++) 
		for (int j=0; j<cipher.length(); j++) 
			if (rail[i][j] == '*' && index<cipher.length()) 
				rail[i][j] = cipher[index++]; 


	// now read the matrix in zig-zag manner to construct 
	// the resultant text 
	string result; 

	row = 0, col = 0; 
	for (int i=0; i< cipher.length(); i++) 
	{ 
		// check the direction of flow 
		if (row == 0) 
			dir_down = true; 
		if (row == key-1) 
			dir_down = false; 

		// place the marker 
		if (rail[row][col] != '*') 
			result.push_back(rail[row][col++]); 

		// find the next row using direction flag 
		dir_down?row++: row--; 
	} 
	return result; 
} 

//driver program to check the above functions 
int main() 
{ 
	cout << encryptRailFence("attack at once", 2) << endl; 
	cout << encryptRailFence("GeeksforGeeks ", 3) << endl; 
	cout << encryptRailFence("defend the east wall", 3) << endl; 

	//Now decryption of the same cipher-text 
	cout << decryptRailFence("GsGsekfrek eoe",3) << endl; 
	cout << decryptRailFence("atc toctaka ne",2) << endl; 
	cout << decryptRailFence("dnhaweedtees alf tl",3) << endl; 

	return 0; 
}*/ 
	
#include <bits/stdc++.h>
using namespace std;

string railfenceEncrypt(string s, int key)
{
    char railfence[key][s.length()];
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            railfence[i][j] = '#';
        }
    }

    bool move_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (row == 0 || row == key - 1)
        {
            move_down = !move_down;
        }

        railfence[row][col++] = s[i];

        if (move_down)
            row++;
        else
            row--;
    }

    cout << "Encryption RailFence is: " << endl;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            cout << railfence[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    string encrypted_text;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (railfence[i][j] != '#')
            {
                encrypted_text.push_back(railfence[i][j]);
            }
        }
    }
    return encrypted_text;
}

string railfenceDecrypt(string s, int key)
{
    char railfence[key][s.length()];
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            railfence[i][j] = '#';
        }
    }

    bool move_down;
    int row = 0, col = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (row == 0)
            move_down = true;
        if (row == key - 1)
        {
            move_down = false;
        }
        railfence[row][col++] = '*';
        if (move_down)
            row++;
        else
            row--;
    }

    int ind = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (railfence[i][j] == '*' && ind < s.length())
            {
                railfence[i][j] = s[ind++];
            }
        }
    }

    cout << "Decryption RailFence is: " << endl;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            cout << railfence[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    string original_text;
    row = 0, col = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (row == 0)
            move_down = true;
        if (row == key - 1)
            move_down = false;

        if (railfence[row][col] != '#')
        {
            original_text.push_back(railfence[row][col++]);
        }

        if (move_down)
            row++;
        else
            row--;
    }

    return original_text;
}

int main()
{
    cout << "Enter the string to be encrypted: ";
    string s;
    cin >> s;
    cout << "Enter the key: ";
    int key;
    cin >> key;
    string encrypted_text = railfenceEncrypt(s, key);
    cout << "Encrypted Text: " << encrypted_text << endl
         << endl;
    string decrypted_text = railfenceDecrypt(encrypted_text, key);
    cout << "Decrypted Text: " << decrypted_text << endl
         << endl;
    return 0;
}
