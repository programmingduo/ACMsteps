//匈牙利算法实现 
int Bipartite(bool vc [][MAX],int nv1,int nv2) { 
    //vc[][]为二分图，nv1,nv2分别为左边的点数 
    int i, j, x, n; 
    //n为最大匹配数 
    int q[MAX], prev[MAX], qs, qe; 
    //q是BFS用的队列，prev是用来记录交错链的，同时也用来记录右边的点是否被找过
    int vm1[MAX], vm2[MAX]; 
    //vm1,vm2分别表示两边的点与另一边的哪个点相匹配 
    n = 0; 
    for( i = 0; i < nv1; i++ ) vm1[i] = -1; 
    for( i = 0; i < nv2; i++ ) vm2[i] = -1; //初始化所有点为未被匹配的状态
    for( i = 0; i < nv1; i++ ) { 
        if(vm1[i] != -1)continue;
        //对于左边每一个未被匹配的点进行一次BFS找交错链 
        
        for( j = 0; j < nv2; j++ ) prev[j] = -2; 
        //每次BFS时初始化右边的点
         
        qs = qe = 0; //初始化BFS的队列 
        //下面这部分代码从初始的那个点开始，先把它能找的的右边的点放入队列
        //★稍微改一下可以适用于用邻接表实现的二分图 
        for( j = 0; j < nv2; j++ ) if( vc[i][j] ) { 
            prev[j] = -1; 
            q[qe++] = j; 
        } 
         
        while( qs < qe ) { //BFS
            x = q[qs]; 
            if( vm2[x] == -1 ) break; 
            //如果找到一个未被匹配的点，则结束，找到了一条交错链 
            qs++; 
            //下面这部分是扩展结点的代码，★稍微改一下可以适用于用邻接表实现的二分图 
            for( j = 0; j < nv2; j++ ) if( prev[j] == -2 && vc[vm2[x]][j] ) { 
                //如果该右边点是一个已经被匹配的点，则vm2[x]是与该点相匹配的左边点 
                //从该左边点出发，寻找其他可以找到的右边点 
                prev[j] = x; 
                q[qe++] = j; 
            } 
        } 
        if( qs == qe ) continue; //没有找到交错链 
        
        //更改交错链上匹配状态 
        while( prev[x] > -1 ) { 
            vm1[vm2[prev[x]]] = x; 
            vm2[x] = vm2[prev[x]]; 
            x = prev[x]; 
        } 
        vm2[x] = i; 
        vm1[i] = x; 
        
        //匹配的边数加一 
        n++; 
    } 
    return n; 
} 
