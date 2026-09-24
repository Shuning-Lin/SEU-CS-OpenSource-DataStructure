import numpy as np
#定义稀疏矩阵类
class SparseMatrix:
    def __init__(self,rows,cols,triples):
        #初始化：rows行、cols列，triples是非零元列表[(行,列,值),...]
        self.rows=rows
        self.cols=cols
        self.triples=triples

    def row_size(self):
        #统计每一列的非零元个数（也就是转置后每一行该放几个元素）
        row_size=[0 for i in range(self.cols)]
        for i in range(len(self.triples)):
            row_size[self.triples[i][1]]+=1
        return row_size
    
    def row_start(self):
        #求每一列在转置结果里的起始下标：前面各列的非零元个数累加起来
        row=self.row_size()
        row_start=[0 for i in range(self.cols)]
        for i in range(1,self.cols):
            row_start[i]=row_start[i-1]+row[i-1]
        return row_start
    
    def fast_transpose(self):
        #快速转置：一趟扫描把每个三元组直接放进结果数组的确定位置，时间复杂度O(n)
        row=self.row_start()
        result=[() for i in range(len(self.triples))]
        for triple in self.triples:
            temp=(triple[1],triple[0],triple[2])
            result[row[temp[0]]]=temp
            row[temp[0]]+=1
        return SparseMatrix(self.cols,self.rows,result)

    
    #------- 以下矩阵还原，跟转置算法无关 -------
    def to_dense(self):
        #还原成二维列表，方便观察和测试
        dense=[[0 for j in range(self.cols)] for i in range(self.rows)]
        for r,c,v in self.triples:
            dense[r][c]=v
        return dense


if __name__=="__main__":
    test=SparseMatrix(4,4,[(0,1,12),(0,2,9),(2,0,-3),(3,2,24)])
    visual=np.array(test.to_dense())
    print("测试矩阵可视化:\n",visual)
    visual=np.array(test.fast_transpose().to_dense())
    print("测试矩阵转置可视化:\n",visual)
#注：GPT-6 Astra(Ultra)后期注释以及部分代码的Debug,Coding由Shuning_Lin同学主导。
