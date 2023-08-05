# HPC Project: Parallel Implementation of Prefix-Sum Algorithm
The present programs namely strategy-1-parallel.c, strategy-1-serial.c, strategy-2-parallel.c and strategy-2-serial.c are parallel and serial implementation of Prefix-Sum algorithm using two different strategies.

## Getting Started

The above programs need to be kept into the folder of all_codes which is in the repository  [letshpcorg/letshpcsample/collect_data_without_perf](https://github.com/letshpcorg/letshpcsample/tree/master/collect_data_without_perf).
## Running the tests
### Regarding code modification and running using script
* See codes on github repo ["https://github.com/letshpcorg/letshpcsample"](https://github.com/letshpcorg/letshpcsample) and modify your codes accordingly so that they can be run automatically using script.
* Put the codes in a folder named 'all_codes'. Keep the name format as id1-id2-problem_name-approach_name and set problem_name and approach_name from maps.py file and keep serial and parallel programs in same folder.
* Download the scripts from the repository.
* Adjust number of processors and problem size in maps.py for the given problem. 
* Do ./run_script_without_perf.sh to start data collection and generate csv file.
* Make sure you run the code for at least 10 iterations to obtain other statistics.
* Run the script on multi-processor machines or cluster. 

## Generating graphs
* Use Google Chrome for this part.
* Go to letshpc.herokuapp.com
* In Analysis Tools, select "Analyse Custom Data"
* Using 'Normal' option, upload CSV file "combined_logs.csv", generated after running script.
* Ignore the error in red. Select all the cores and press 'Update'.
* Adjust scale and metric. Choose 'Mean' as statistic. Make sure the scale of x and y-axis is proper and both the axes are labelled.


## Built With

* [OpenMP](https://www.openmp.org/) - API specification for parallel computing
* [C](https://github.com/search?q=C) - Implementation of algorithm


## Authors
* **Raj Patel** *201701422*
* **Shubh Desai** *201701466*
