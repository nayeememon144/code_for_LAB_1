#include<bits/stdc++.h>
using namespace std;
class job{
public:
    char id;
    int deadline;
    int profit;
    job(){

    }
};
class jobscheduler{
private:
    job* jobs;
    int n;
public:
    jobscheduler(job arr[],int sizee){
        jobs = arr;
        n = sizee;
    }
    void sortjob(){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(jobs[i].profit < jobs[j].profit){
                    job temp = jobs[i];
                    jobs[i] = jobs[j];
                    jobs[j] = temp;
                }
            }
        }
    }
    void scheduler(){
        sortjob();
        int maxdeadline = 0;
        for(int i = 0; i < n; i++){
            if(jobs[i].deadline > maxdeadline){
                maxdeadline = jobs[i].deadline;
            }
        }
        int slot[maxdeadline];
        char res[maxdeadline];
        for(int i = 0; i < maxdeadline; i++){
            slot[i] = 0;
        }
        int totalprofit = 0;
        for(int i = 0; i < n; i++){
            for(int j = jobs[i].deadline - 1; j >= 0; j--){
                if(slot[j] == 0){
                    slot[j] = 1;
                    res[j] = jobs[i].id;
                    totalprofit = totalprofit + jobs[i].profit;
                    break;
                }
            }
        }

        cout << "\nScheduled job : ";
        for(int i = 0; i < maxdeadline; i++){
            if(slot[i]){
                cout << res[i] << " ";
            }
        }
        cout << "Maximum profit is : " << totalprofit << endl;
    }
};
int main(){
    int n;
    cout << "Enter the number of the jobs : ";
    cin >> n;
    job* arr = new job[n];
    cout << "Enter the jobs (id deadline profit) : \n";
    for(int i = 0; i < n; i++){
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    jobscheduler schedu(arr,n);
    schedu.scheduler();
    return 0;

}
