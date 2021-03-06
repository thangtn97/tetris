#pragma once

class Piece {
  private:
   int pieces[7][4][4][4] = {
     {
       {
         //I
         {0,1,0,0},
         {0,1,0,0},
         {0,1,0,0},
         {0,1,0,0}
       },
       {
         {0,0,0,0},
         {1,1,1,1},
         {0,0,0,0},
         {0,0,0,0}
       },
       {
         {0,1,0,0},
         {0,1,0,0},
         {0,1,0,0},
         {0,1,0,0}
       }, 
       {
         {0,0,0,0},
         {1,1,1,1},
         {0,0,0,0},
         {0,0,0,0}
       },
     },
      
     {
       {  //L
         {0,1,0,0},
         {0,1,0,0},
         {0,1,1,0},
         {0,0,0,0}
       },
       {
         {0,0,0,0},
         {0,1,1,1},
         {0,1,0,0},
         {0,0,0,0}
       },
       {
         {0,0,0,0},
         {0,1,1,0},
         {0,0,1,0},
         {0,0,1,0}
       }, 
       {
         
         {0,0,0,0},
         {0,0,1,0},
         {1,1,1,0},
         {0,0,0,0}
       },
    },
    {
      {
       //L reverse
         {0,1,0,0},
         {0,1,0,0},
         {0,1,1,0},
         {0,0,0,0}
       },
       {
         {0,0,0,0},
         {0,1,1,1},
         {0,1,0,0},
         {0,0,0,0}
       }, 
       {
         {0,0,0,0},
         {0,1,1,0},
         {0,0,1,0},
         {0,0,1,0}
       },
       {
         {0,0,0,0},
         {0,0,1,0},
         {1,1,1,0},
         {0,0,0,0}
       },
     },
     {
       {//z
         {0,0,0,0},
         {1,1,0,0},
         {0,1,1,0},
         {0,0,0,0}
       },
       {
         {0,0,1,0},
         {0,1,1,0},
         {0,1,0,0},
         {0,0,0,0}
       },
       {
         {0,0,0,0},
         {1,1,0,0},
         {0,1,1,0},
         {0,0,0,0}
       }, 
       {
         {0,0,1,0},
         {0,1,1,0},
         {0,1,0,0},
         {0,0,0,0}
       },
     },
     {
       {
         //z reverse
         {0,0,0,0},
         {0,0,1,1},
         {0,1,1,0},
         {0,0,0,0}
       },
       {
         {0,1,0,0},
         {0,1,1,0},
         {0,0,1,0},
         {0,0,0,0}
       },
       {
         {0,0,0,0},
         {0,0,1,1},
         {0,1,1,0},
         {0,0,0,0}
       }, 
       {
         {0,1,0,0},
         {0,1,1,0},
         {0,0,1,0},
         {0,0,0,0}
       },
     },
     {
       { //T
         {1,1,1,0},
         {0,1,0,0},
         {0,0,0,0},
         {0,0,0,0}
       },
       {
         {0,0,1,0},
         {0,1,1,0},
         {0,0,1,0},
         {0,0,0,0}
       },
       {
         {0,0,0,0},
         {0,1,0,0},
         {1,1,1,0},
         {0,0,0,0}
       }, 
       {
         {0,1,0,0},
         {1,1,0,0},
         {0,1,0,0},
         {0,0,0,0}
       },
     },
     {
       { //O
         {0,1,1,0},
         {0,1,1,0},
         {0,0,0,0},
         {0,0,0,0}
       },
       {
         {0,1,1,0},
         {0,1,1,0},
         {0,0,0,0},
         {0,0,0,0}
       },
       {
         {0,1,1,0},
         {0,1,1,0},
         {0,0,0,0},
         {0,0,0,0}
       }, 
       {
         {0,1,1,0},
         {0,1,1,0},
         {0,0,0,0},
         {0,0,0,0}
       },
     },
   };
  public:
    bool getBlock(int type, int rotate, int px, int py);
};

