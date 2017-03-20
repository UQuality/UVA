#include <bits/stdc++.h>
#define MAX 12
#define INF 1000
#define REP(i,a,n) for(int i = a; i<n; i++)
#define s second
#define f first
#define e empty()
#define p push
#define fr front()
#define pp pop()

using namespace std;
typedef pair<int,int> ii;

struct state
{
    ii cA;
    ii cB;
    ii cC;
    int val;

    bool operator!=( const state& i)
    {
        return !(i.cA == cA && i.cB==cB && i.cC == cC);
    }
};

typedef queue<state> qii;

char mat[MAX][MAX];
int res[MAX][MAX][MAX][MAX][MAX][MAX];
int resp,n;
ii A,B,C;

int can(ii p)
{
    if(p.f>=0 && p.f<n && p.s>=0 && p.s<n)
    {
        if(mat[p.f][p.s]=='#')
            return 0;

        return 1;
    }
    return -1;
}

state iz(state cur)
{

    state ret;
    ii cuA(cur.cA.f,cur.cA.s-1);
    ii cuB(cur.cB.f,cur.cB.s-1);
    ii cuC(cur.cC.f,cur.cC.s-1);
    bool rba=0,rbb=0,rbc=0;
    if(can(cuA)==1||can(cuB)==1||can(cuC)==1)
    {
        if(can(cuA)==1 && (cuA != cuB && cuA != cuC ))
        {
            ret.cA = cuA;
            //printf("Mueve A(%d,%d) a A(%d,%d)\n",cur.cA.f,cur.cA.s,ret.cA.f,ret.cA.s);
        }
        else
            ret.cA = cur.cA;

        if(can(cuB)==1 &&  (cuB != cuA && cuB != cuC))
        {
            ret.cB = cuB;
            //printf("Mueve B(%d,%d) a B(%d,%d)\n",cur.cB.f,cur.cB.s,ret.cB.f,ret.cB.s);
        }
        else
            ret.cB = cur.cB;

        if(can(cuC)==1 &&  (cuC != cuB && cuC != cuA))
        {
            ret.cC = cuC;
            //printf("Mueve C(%d,%d) a C(%d,%d)\n",cur.cC.f,cur.cC.s,ret.cC.f,ret.cC.s);
        }
        else
            ret.cC = cur.cC;

        if((cuA==ret.cB || cuA == ret.cC) && cuA == ret.cA)
        {
            cuA = cur.cA;
            rba=true;
            //printf("Rollback de A(%d,%d) a A(%d,%d)\n",ret.cA.f,ret.cA.s,cur.cA.f,cur.cA.s);
        }

        if((cuB == ret.cA || cuB == ret.cC) && cuB == ret.cB)
        {
            cuB = cur.cB;
            rbb = true;
            //printf("Rollback de B(%d,%d) a B(%d,%d)\n",ret.cB.f,ret.cB.s,cur.cB.f,cur.cB.s);
        }
        if((cuC == ret.cA || cuC == ret.cB) && cuC == ret.cC)
        {
            cuC = cur.cC;
            rbc=true;
            //printf("Rollback de C(%d,%d) a C(%d,%d)\n",ret.cC.f,ret.cC.s,cur.cC.f,cur.cC.s);
        }

        rba?ret.cA = cuA:ret.cA=ret.cA;
        rbb?ret.cB = cuB:ret.cB=ret.cB;
        rbc?ret.cC = cuC:ret.cC=ret.cC;
        ret.val=cur.val+1;
    }
    else
    {
        ret = cur;
    }

    return ret;
}

state de(state cur)
{

    state ret;
    ii cuA(cur.cA.f,cur.cA.s+1);
    ii cuB(cur.cB.f,cur.cB.s+1);
    ii cuC(cur.cC.f,cur.cC.s+1);
    bool rba=0,rbb=0,rbc=0;
    if(can(cuA)==1||can(cuB)==1||can(cuC)==1)
    {
        if(can(cuA)==1 && (cuA != cuB && cuA != cuC ))
        {
            ret.cA = cuA;
            //printf("Mueve A(%d,%d) a A(%d,%d)\n",cur.cA.f,cur.cA.s,ret.cA.f,ret.cA.s);
        }
        else
            ret.cA = cur.cA;

        if(can(cuB)==1 &&  (cuB != cuA && cuB != cuC))
        {
            ret.cB = cuB;
            //printf("Mueve B(%d,%d) a B(%d,%d)\n",cur.cB.f,cur.cB.s,ret.cB.f,ret.cB.s);
        }
        else
            ret.cB = cur.cB;

        if(can(cuC)==1 &&  (cuC != cuB && cuC != cuA))
        {
            ret.cC = cuC;
            //printf("Mueve C(%d,%d) a C(%d,%d)\n",cur.cC.f,cur.cC.s,ret.cC.f,ret.cC.s);
        }
        else
            ret.cC = cur.cC;

        if((cuA==ret.cB || cuA == ret.cC) && cuA == ret.cA)
        {
            cuA = cur.cA;
            rba=true;
            //printf("Rollback de A(%d,%d) a A(%d,%d)\n",ret.cA.f,ret.cA.s,cur.cA.f,cur.cA.s);
        }

        if((cuB == ret.cA || cuB == ret.cC) && cuB == ret.cB)
        {
            cuB = cur.cB;
            rbb = true;
            //printf("Rollback de B(%d,%d) a B(%d,%d)\n",ret.cB.f,ret.cB.s,cur.cB.f,cur.cB.s);
        }
        if((cuC == ret.cA || cuC == ret.cB) && cuC == ret.cC)
        {
            cuC = cur.cC;
            rbc=true;
            //printf("Rollback de C(%d,%d) a C(%d,%d)\n",ret.cC.f,ret.cC.s,cur.cC.f,cur.cC.s);
        }

        rba?ret.cA = cuA:ret.cA=ret.cA;
        rbb?ret.cB = cuB:ret.cB=ret.cB;
        rbc?ret.cC = cuC:ret.cC=ret.cC;
        ret.val=cur.val+1;
    }
    else
    {
        ret = cur;
    }

    return ret;

}

state ar(state cur)
{
    bool rba=0,rbb=0,rbc=0;
    state ret;
    ii cuA(cur.cA.f-1,cur.cA.s);
    ii cuB(cur.cB.f-1,cur.cB.s);
    ii cuC(cur.cC.f-1,cur.cC.s);
    if(can(cuA)==1||can(cuB)==1||can(cuC)==1)
    {
        if(can(cuA)==1 && (cuA != cuB && cuA != cuC ))
        {
            ret.cA = cuA;
            //printf("Mueve A(%d,%d) a A(%d,%d)\n",cur.cA.f,cur.cA.s,ret.cA.f,ret.cA.s);
        }
        else
            ret.cA = cur.cA;

        if(can(cuB)==1 &&  (cuB != cuA && cuB != cuC))
        {
            ret.cB = cuB;
            //printf("Mueve B(%d,%d) a B(%d,%d)\n",cur.cB.f,cur.cB.s,ret.cB.f,ret.cB.s);
        }
        else
            ret.cB = cur.cB;

        if(can(cuC)==1 &&  (cuC != cuB && cuC != cuA))
        {
            ret.cC = cuC;
            //printf("Mueve C(%d,%d) a C(%d,%d)\n",cur.cC.f,cur.cC.s,ret.cC.f,ret.cC.s);
        }
        else
            ret.cC = cur.cC;

        if((cuA==ret.cB || cuA == ret.cC) && cuA == ret.cA)
        {
            cuA = cur.cA;
            rba=true;
            //printf("Rollback de A(%d,%d) a A(%d,%d)\n",ret.cA.f,ret.cA.s,cur.cA.f,cur.cA.s);
        }

        if((cuB == ret.cA || cuB == ret.cC) && cuB == ret.cB)
        {
            cuB = cur.cB;
            rbb = true;
            //printf("Rollback de B(%d,%d) a B(%d,%d)\n",ret.cB.f,ret.cB.s,cur.cB.f,cur.cB.s);
        }
        if((cuC == ret.cA || cuC == ret.cB) && cuC == ret.cC)
        {
            cuC = cur.cC;
            rbc=true;
            //printf("Rollback de C(%d,%d) a C(%d,%d)\n",ret.cC.f,ret.cC.s,cur.cC.f,cur.cC.s);
        }

        rba?ret.cA = cuA:ret.cA=ret.cA;
        rbb?ret.cB = cuB:ret.cB=ret.cB;
        rbc?ret.cC = cuC:ret.cC=ret.cC;
        ret.val=cur.val+1;
    }
    else
    {
        ret = cur;
    }

    return ret;

}

state ab(state cur)
{
    state ret;
    ii cuA(cur.cA.f+1,cur.cA.s);
    ii cuB(cur.cB.f+1,cur.cB.s);
    ii cuC(cur.cC.f+1,cur.cC.s);
    bool rba=0,rbb=0,rbc=0;
    if(can(cuA)==1||can(cuB)==1||can(cuC)==1)
    {
        if(can(cuA)==1 && (cuA != cuB && cuA != cuC ))
        {
            ret.cA = cuA;
            //printf("Mueve A(%d,%d) a A(%d,%d)\n",cur.cA.f,cur.cA.s,ret.cA.f,ret.cA.s);
        }
        else
            ret.cA = cur.cA;

        if(can(cuB)==1 &&  (cuB != cuA && cuB != cuC))
        {
            ret.cB = cuB;
            // printf("Mueve B(%d,%d) a B(%d,%d)\n",cur.cB.f,cur.cB.s,ret.cB.f,ret.cB.s);
        }
        else
            ret.cB = cur.cB;

        if(can(cuC)==1 &&  (cuC != cuB && cuC != cuA))
        {
            ret.cC = cuC;
            // printf("Mueve C(%d,%d) a C(%d,%d)\n",cur.cC.f,cur.cC.s,ret.cC.f,ret.cC.s);
        }
        else
            ret.cC = cur.cC;

        if((cuA==ret.cB || cuA == ret.cC) && cuA == ret.cA)
        {
            cuA = cur.cA;
            rba=true;
            // printf("Rollback de A(%d,%d) a A(%d,%d)\n",ret.cA.f,ret.cA.s,cur.cA.f,cur.cA.s);
        }

        if((cuB == ret.cA || cuB == ret.cC) && cuB == ret.cB)
        {
            cuB = cur.cB;
            rbb = true;
            // printf("Rollback de B(%d,%d) a B(%d,%d)\n",ret.cB.f,ret.cB.s,cur.cB.f,cur.cB.s);
        }
        if((cuC == ret.cA || cuC == ret.cB) && cuC == ret.cC)
        {
            cuC = cur.cC;
            rbc=true;
            // printf("Rollback de C(%d,%d) a C(%d,%d)\n",ret.cC.f,ret.cC.s,cur.cC.f,cur.cC.s);
        }

        rba?ret.cA = cuA:ret.cA=ret.cA;
        rbb?ret.cB = cuB:ret.cB=ret.cB;
        rbc?ret.cC = cuC:ret.cC=ret.cC;
        ret.val=cur.val+1;
    }
    else
    {
        ret = cur;
    }

    return ret;

}


bool isEnd(state pe)
{
    return mat[pe.cA.f][pe.cA.s]=='X' && mat[pe.cB.f][pe.cB.s]=='X' && mat[pe.cC.f][pe.cC.s]=='X';
}

bool notSame(ii p1, ii p2, ii p3)
{
    return !(p1==p2 || p2==p3 || p1==p3);
}

bool validar(state st)
{
    if(can(st.cA)!=-1 && can(st.cB)!=-1 && can(st.cC)!=-1)
    {
        if(res[st.cA.f][st.cA.s][st.cB.f][st.cB.s][st.cC.f][st.cC.s]>st.val && notSame(st.cA,st.cB,st.cC))
        {
            res[st.cA.f][st.cA.s][st.cB.f][st.cB.s][st.cC.f][st.cC.s]=st.val;
            // printf("En A(%d,%d) B(%d,%d) C(%d,%d) marcado con %d\n",st.cA.f,st.cA.s,st.cB.f,st.cB.s,st.cC.f,st.cC.s,st.val);
            return true;
        }//else
        //   printf("No jue menol A(%d,%d) B(%d,%d) C(%d,%d) -> %d a %d\n",st.cA.f,st.cA.s,st.cB.f,st.cB.s,st.cC.f,st.cC.s,st.val,res[st.cA.f][st.cA.s][st.cB.f][st.cB.s][st.cC.f][st.cC.s]);
    }//else
    //  printf("Ni entro con A(%d,%d) B(%d,%d) C(%d,%d),lol\n",st.cA.f,st.cA.s,st.cB.f,st.cB.s,st.cC.f,st.cC.s);
    return false;
}

void bfs()
{
    char con;
    qii cola;
    state curr,enc;
    curr.cA = A;
    curr.cB = B;
    curr.cC = C;
    curr.val = 0;
    res[A.f][A.s][B.f][B.s][C.f][C.s]=0;
    cola.p(curr);

    while(!cola.e)
    {
        curr = cola.fr;
        cola.pp;

        //printf("cur = A(%d,%d) B(%d,%d) C(%d,%d) con %d\n",curr.cA.f,curr.cA.s,curr.cB.f,curr.cB.s,curr.cC.f,curr.cC.s,curr.val);

        if(isEnd(curr))
        {
            resp > curr.val? resp = curr.val:resp = resp;
            //     printf("REACHED!!!!!\n");
        }

        enc = iz(curr);
        // if(enc.cA == ii(3,3) && enc.cB == ii(1,3) && enc.cC == ii(2,2)) printf("Aqui jueeeee!!!!!!!! con A(%d,%d) B(%d,%d) C(%d,%d)\n",curr.cA.f,curr.cA.s,curr.cB.f,curr.cB.s,curr.cC.f,curr.cC.s);
        if(enc!=curr && validar(enc))
            cola.p(enc);

        enc = de(curr);
        //if(enc.cA == ii(3,3) && enc.cB == ii(1,3) && enc.cC == ii(2,2)) printf("Aqui jueeeee!!!!!!!! con A(%d,%d) B(%d,%d) C(%d,%d)\n",curr.cA.f,curr.cA.s,curr.cB.f,curr.cB.s,curr.cC.f,curr.cC.s);
        if(enc!=curr && validar(enc))
            cola.p(enc);

        enc = ar(curr);
        // if(enc.cA == ii(3,3) && enc.cB == ii(1,3) && enc.cC == ii(2,2)) printf("Aqui jueeeee!!!!!!!! con A(%d,%d) B(%d,%d) C(%d,%d)\n",curr.cA.f,curr.cA.s,curr.cB.f,curr.cB.s,curr.cC.f,curr.cC.s);
        if(enc!=curr && validar(enc))
            cola.p(enc);

        enc = ab(curr);
        // if(enc.cA == ii(3,3) && enc.cB == ii(1,3) && enc.cC == ii(2,2)) printf("Aqui jueeeee!!!!!!!! con A(%d,%d) B(%d,%d) C(%d,%d)\n",curr.cA.f,curr.cA.s,curr.cB.f,curr.cB.s,curr.cC.f,curr.cC.s);
        if(enc!=curr && validar(enc))
            cola.p(enc);
    }
}

void llenar()
{
    REP(i,0,n)
    {
        REP(j,0,n)
        {
            REP(k,0,n)
            {
                REP(l,0,n)
                {
                    REP(m,0,n)
                    {
                        REP(o,0,n)
                        {
                            res[i][j][k][l][m][o]=INF;
                        }
                    }
                }
            }
        }
    }
}

int main()
{

    int c=0,casos;
    char aux;

    scanf("%d",&casos);

    while(c<casos)
    {

        resp = INF;
        printf("Case %d: ", c+1);
        scanf("%d\n",&n);
        llenar();

        REP(i,0,n)
        {
            REP(j,0,n)
            {
                scanf("%c",&aux);
                mat[i][j]=aux;
                if(aux == 'A')
                {
                    A.f=i;
                    A.s=j;
                }
                if(aux == 'B')
                {
                    B.f=i;
                    B.s=j;
                }
                if(aux == 'C')
                {
                    C.f=i;
                    C.s=j;
                }
            }

            scanf("%c",&aux);
        }

        bfs();
        if (resp!=INF)
            printf("%d\n", resp);
        else
            puts("trapped");
        c++;
    }


    return 0;
}
