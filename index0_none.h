#ifndef INDEX_0_NONE_H
#define INDEX_0_NONE_H

// 索引0位置不存储数据 = 1
// 索引0位置存储数据 = 0
const int INDEX_0_FLAG = 1;

int getParent(int index) { return index / 2; }

int getLeftChird(int index) { return index * 2; }

int getRightChird(int index) { return index * 2 + 1; }

// 最后一个非叶子节点
int getNotLeaf(int count) { return count / 2; }

#endif // INDEX_0_NONE_H