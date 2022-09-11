//二分查找前提条件是数组有序的

int binarySearch(vector<int> &nums,int &target) {
	int left = 0;
	int right = nums.size()-1;
	// 左闭和右闭
	while(left<=right) {
		int middle = (left+right)/2;
		if(nums[middle]<target){
			left = middle+1;
		}else if(nums[middle]>target) {
			right = middle-1;
		}else {
			return middle;
		}
	}
	return -1; // 没有找到target对应的下标则返回-1；
}
int main()
{
   vector<int> nums = {1,2,3,5,8,10,12,13};
	int target = 12;
	int result = binarySearch(nums,target);
	cout<<result<<endl;
	return 0;
}
