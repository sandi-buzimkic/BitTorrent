#include <iostream>
#include <fstream>
#include <string>
int parseInt(const std::string& data,int& pos){
	pos++; //skips i of data
	int result=0;
	while(data[pos]!='e'){
		result= result * 10 + (data[pos]-'0');
		pos++;
	}
	pos++; //skips e of the data
	return result;
}
std::string parseString(const std::string& data,int& pos){
   	int strLen=0; 
	while(data[pos]!=':'){
		strLen = strLen*10 + (data[pos]-'0');
		pos++;
	}
	pos++; // skip ":"
	std::string result= data.substr(pos, strLen);
	pos+=strLen;
	return result;
}
int main() {
    std::cout << "BitTorrent client starting..." << std::endl;

    std::string filename = "big-buck-bunny.torrent";
    
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Could not open file: " << filename << std::endl;
        return 1;
    }

    std::cout << "Opened torrent file successfully!" << std::endl;
    
    /*std::string number="i422e";
    int pos=0;
    std::cout<<"number is: "<<parseInt(number,pos)<<" \n";
    
    std::string example="9:bencoding";
    pos=0;
    std::cout<<"string is: "<<parseString(example,pos)<<" \n";
    return 0;*/
    
    std::string exampleData = "d8:announce31:http://example.com datei1677655000e4:infod6:lengthi1048576e4:name10:sample.txte12:piece lengthi16384e6:pieces20:abcdefghij1234567890ee";

}
/*

Press **F11** to compile and run. This is your foundation.

---

### Step 4: The Roadmap — Build in This Exact Order

Do **not** try to build everything at once. Follow this order:
```
Phase 1: Bencode Parser        ← .torrent files use this format
Phase 2: Torrent File Reader   ← extract tracker URL, file name, pieces
Phase 3: Tracker Communication ← HTTP request to get peers
Phase 4: Peer Connection       ← TCP sockets, handshake
Phase 5: Piece Downloading     ← request/receive data blocks
Phase 6: SHA1 Verification     ← confirm pieces aren't corrupted
Phase 7: Write to Disk         ← save the actual file
*/