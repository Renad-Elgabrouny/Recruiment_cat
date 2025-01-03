### TASK2

This document summarizes the steps taken during the task 2. The dataset contains information about cars, including their brand, model, manufacturing year, type, rating, color, duty, fuel type, cylinder count, gear type, capacity, odometer reading, airbags, and price.

---

#### **1. Loading the Dataset**
- The dataset was loaded using `pandas.read_csv()` from the provided CSV file (`train.csv`).
- The dataset contains **7,000 rows** and **15 columns**.

---

#### **2. Initial Data Inspection**
- **`df.head()`**: Displayed the first 5 rows of the dataset to get a sense of the data structure.
- **`df.info()`**: Checked the data types and missing values:
  - Most columns are of type `object` (string), except for `ID` (int64), `rating` (float64), and `price` (int64).
  - Several columns have missing values, including `Brand`, `VehicleModel`, `ManufacturingYear`, `Type`, `rating`, `color`, `fuel`, and `type of gear`.
- **`df.describe()`**: Provided summary statistics for numerical columns (`ID`, `rating`, `price`):
  - `rating` ranges from **-4 to 10**, which may indicate invalid or outlier values.
  - `price` ranges from **3 to 49,889**.
- **`df.describe(include='O')`**: Provided summary statistics for categorical columns:
  - The most frequent values for some columns:
    - `Brand`: "toyota" (497 occurrences).
    - `VehicleModel`: "Prius" (113 occurrences).
    - `ManufacturingYear`: "2012" (429 occurrences).
    - `Type`: "sedan" (1,160 occurrences).
    - `color`: "Jet Black" (1,239 occurrences).
    - `fuel`: "Gas" (3,272 occurrences).
    - `CylinderCount`: "4.0" (2,638 occurrences).
    - `type of gear`: "auto" (2,870 occurrences).
    - `capacity`: "2" (1,261 occurrences).
    - `Odometer`: "0 km" (79 occurrences).
    - `airbags`: "12" (830 occurrences).

---

#### **3. Checking for Duplicates**
- **`df.duplicated().sum()`**: Checked for duplicate rows in the dataset.
  - **Result**: No duplicate rows were found.

---

#### **4. Checking for Missing Values**
- **`df.isna().sum() / len(df) * 100`**: Calculated the percentage of missing values in each column:
  - `Brand`: **10.09%** missing.
  - `VehicleModel`: **9.96%** missing.
  - `ManufacturingYear`: **9.93%** missing.
  - `Type`: **9.79%** missing.
  - `rating`: **9.86%** missing.
  - `color`: **30.34%** missing.
  - `fuel`: **9.94%** missing.
  - `type of gear`: **9.89%** missing.
  - Other columns (`ID`, `Duty`, `CylinderCount`, `capacity`, `Odometer`, `airbags`, `price`) have **no missing values**.

---

#### **5. Renaming Columns**
- **`df.rename(columns={'#airbags': 'airbags'}, inplace=True)`**:
  - Renamed the column `#airbags` to `airbags` for easier access and consistency.

---

### Data Cleaning Phase

---

#### **1. Cleaning the `Brand` Column**
- **Initial State**: The `Brand` column had **185 unique values**, many of which were inconsistent or contained irrelevant phrases (e.g., "I love TOYOTA").
- **Cleaning Steps**:
  - Removed phrases like "I love" and "is the best".
  - Standardized brand names using a mapping dictionary (e.g., "toyota" → "Toyota").
- **Result**: Reduced to **54 unique values**, making the column more consistent.

---

#### **2. Cleaning the `VehicleModel` Column**
- **Initial State**: The `VehicleModel` column had **1480 unique values**, many of which were inconsistent or contained unnecessary phrases (e.g., "I have the fastest model ever...").
- **Cleaning Steps**:
  - Removed phrases like "I have the fastest model ever..." and "my model which is".
  - Standardized model names by extracting the first word after cleaning.
- **Result**: Reduced to **414 unique values**, significantly improving consistency.

---

#### **3. Cleaning the `ManufacturingYear` Column**
- **Initial State**: The `ManufacturingYear` column had **555 unique values**, including invalid formats (e.g., "1-1-2003", "14years old").
- **Cleaning Steps**:
  - Extracted valid years from date formats (e.g., "1-1-2003" → 2003).
  - Converted "years old" values to actual years (e.g., "14years old" → 2010, assuming the current year is 2024).
  - Filtered out invalid years (e.g., years outside the range 1886–2024).
- **Result**: Reduced to **66 unique valid years**.

---

#### **4. Cleaning the `Type` Column**
- **Initial State**: The `Type` column had **81 unique values**, many of which were inconsistent or contained unnecessary prefixes (e.g., "WOOW Sedan").
- **Cleaning Steps**:
  - Removed prefixes like "WOOW".
  - Standardized type names using a mapping dictionary (e.g., "sedan" → "Sedan").
- **Result**: Reduced to **12 unique values**, including "Sedan", "Minivan", "Hatchback", etc.

---

#### **5. Cleaning the `rating` Column**
- **Initial State**: The `rating` column contained negative values and inconsistencies.
- **Cleaning Steps**:
  - Converted all ratings to their absolute values.
- **Result**: Ensured all ratings are non-negative.

---

#### **6. Cleaning the `Duty` Column**
- **Initial State**: The `Duty` column had **1173 unique values**, many of which were text phrases (e.g., "I had to pay a substantial $1249 levy...").
- **Cleaning Steps**:
  - Extracted numeric values from text using regex.
- **Result**: Converted the column to numeric values, making it suitable for analysis.

---

#### **7. Cleaning the `fuel` Column**
- **Initial State**: The `fuel` column had inconsistent values (e.g., "Dies", "hyb").
- **Cleaning Steps**:
  - Standardized fuel types using a mapping dictionary (e.g., "Dies" → "Diesel").
- **Result**: Reduced to consistent fuel types like "Gasoline", "Diesel", and "Hybrid".

---

#### **8. Cleaning the `CylinderCount` Column**
- **Initial State**: The `CylinderCount` column had inconsistent values (e.g., "4.0 cyl").
- **Cleaning Steps**:
  - Extracted numeric values using the same function as for the `Duty` column.
- **Result**: Converted the column to numeric values.

---

#### **9. Cleaning the `type of gear` Column**
- **Initial State**: The `type of gear` column had inconsistent values (e.g., "R", "auto").
- **Cleaning Steps**:
  - Standardized gear types using a mapping dictionary (e.g., "R" → "Automatic").
- **Result**: Reduced to consistent values like "Automatic" and "Manual".

---

#### **10. Cleaning the `capacity` Column**
- **Initial State**: The `capacity` column had inconsistent values (e.g., "2 Turbo").
- **Cleaning Steps**:
  - Extracted numeric values and removed non-numeric parts (e.g., "2 Turbo" → 2.0).
- **Result**: Converted the column to numeric values.

---

#### **11. Cleaning the `Odometer` Column**
- **Initial State**: The `Odometer` column had inconsistent values (e.g., "75492 KM").
- **Cleaning Steps**:
  - Extracted numeric values using the same function as for the `Duty` column.
- **Result**: Converted the column to numeric values.

---

#### **12. Cleaning the `airbags` Column**
- **Initial State**: The `airbags` column had inconsistent values (e.g., "1008", "-96").
- **Cleaning Steps**:
  - Extracted numeric values and capped them between 0 and 12.
- **Result**: Ensured all values are within a valid range.

---

#### **13. Handling Missing Values**
- **Initial State**: Several columns had missing values:
  - `Brand`: **10.09%**
  - `VehicleModel`: **9.96%**
  - `ManufacturingYear`: **9.93%**
  - `Type`: **9.79%**
  - `rating`: **9.86%**
  - `color`: **30.34%**
  - `fuel`: **9.94%**
  - `type of gear`: **9.89%**
- **Next Steps**:
  - Impute missing values based on domain knowledge or statistical methods.
  - Drop rows with excessive missing values if necessary.

---

#### **14. Summary of Data Cleaning**
- **Brand**: Standardized to 54 unique values.
- **VehicleModel**: Reduced to 414 unique values.
- **ManufacturingYear**: Cleaned and reduced to 66 valid years.
- **Type**: Standardized to 12 unique values.
- **rating**: Ensured non-negative values.
- **Duty**: Extracted numeric values from text.
- **fuel**: Standardized to consistent fuel types.
- **CylinderCount**: Extracted numeric values.
- **type of gear**: Standardized to consistent gear types.
- **capacity**: Extracted numeric values.
- **Odometer**: Extracted numeric values.
- **airbags**: Capped values between 0 and 12.

---
### Analysis Phase
---

#### **1. Price Distribution Across Top 15 Brands**
- **Insights**:
  - **BMW, Mercedes-Benz, and SsangYong** show the highest median prices.
  - Almost all brands have outliers above their typical price range.
  - Some brands like **Mercedes-Benz** maintain a consistently high price point (higher bottom whisker).

---

#### **2. Fuel Type Distribution by Top 15 Brands**
- **Insights**:
  - Most brands have **hybrid** fuel types.
  - **Toyota** is the most frequent brand.

---

#### **3. Average Ratings by Top 15 Brands**
- **Insights**:
  - **Toyota and Hyundai** lead the pack with the highest average ratings of approximately **2.5**.
  - The rating scale appears to go from **0 to 3.0**, with most brands scoring above **2.0**.
  - The differences between brands are relatively small, suggesting consistent quality across major manufacturers.

---

#### **4. Price Trends Over Manufacturing Years**
- **Insights**:
  - There's a significant gap in data between approximately **1920 and 1980**.
  - The price spread has become much wider in recent years, indicating greater market segmentation.

---

#### **5. Odometer Reading vs Manufacturing Year**
- **Insights**:
  - The highest odometer readings appear in vehicles from around **1980-2000**.
  - The extremely high readings (e.g., **2 billion**) might indicate potential data recording errors or odometer rollovers.

---

#### **6. Average Number of Airbags and Cylinder Count by Brand**
- **Insights**:
  - **Lexus and BMW** have the highest number of cylinders.
  - **Toyota and Mercedes-Benz** have the highest number of airbags.

---

#### **7. Engine Capacity Distribution by Fuel Type**
- **Insights**:
  - The distribution of engine capacity varies significantly across different fuel types.
  - **Gasoline** and **Diesel** vehicles tend to have higher engine capacities compared to **Hybrid** and **Electric** vehicles.

---

#### **8. Correlation Matrix of Numerical Features**
- **Insights**:
  - **ManufacturingYear** is the most correlated with the price.
  - Other features like **rating**, **capacity**, and **CylinderCount** show weak correlations with price.

---

#### **9. Average Price by Brand**
- **Insights**:
  - **SsangYong** has the highest average price, making it the most luxurious brand in the dataset.
  - Other high-priced brands include **GMC**, **Jeep**, and **Land Rover**.

---

#### **10. Brand Statistics**
- **Insights**:
  - **SsangYong** has the highest average price (**$29,852.75**) and a moderate rating (**2.47**).
  - **Toyota** has a high average rating (**2.58**) and a moderate price (**$12,824.04**).
  - **Mercedes-Benz** has a high number of airbags (**8.97**) and a moderate price (**$13,391.98**).

---

#### **11. Key Insights Summary**
- **Price Distribution**: BMW, Mercedes-Benz, and SsangYong have the highest median prices.
- **Fuel Type**: Most brands have hybrid fuel types, with Toyota being the most frequent brand.
- **Ratings**: Toyota and Hyundai lead with the highest average ratings.
- **Price Trends**: Prices have become more varied in recent years, indicating market segmentation.
- **Odometer Readings**: Highest readings are from vehicles manufactured between 1980-2000.
- **Airbags and Cylinders**: Lexus and BMW have the highest cylinder counts, while Toyota and Mercedes-Benz have the most airbags.
- **Correlations**: Manufacturing year is the most correlated with price.
- **Luxury Brands**: SsangYong is the most luxurious brand based on average price.

---
### Preprocessing and Modeling Phase
---

#### **1. Feature Engineering**
- **Engine Size Categorization**:
  - Created a new feature `EngineSize` by categorizing the `capacity` column into:
    - **Small**: Capacity < 1.5
    - **Medium**: 1.5 ≤ Capacity ≤ 3.0
    - **Large**: Capacity > 3.0
- **Safety Score Categorization**:
  - Created a new feature `SafetyScore` by categorizing the `airbags` column into:
    - **Low**: Airbags ≤ 2
    - **Medium**: 3 ≤ Airbags ≤ 6
    - **High**: Airbags > 6

---

#### **2. Data Splitting**
- Split the dataset into training and testing sets:
  - **Training Set**: 80% of the data.
  - **Testing Set**: 20% of the data.
- **Features (X)**: All columns except `price` and `ID`.
- **Target (y)**: The `price` column.

---

#### **3. Handling Outliers**
- **Skewness Analysis**:
  - Identified that the `Odometer` column has a high skewness value (**41.9**).
- **Yeo-Johnson Transformation**:
  - Applied the Yeo-Johnson transformation to the `Odometer` column to reduce skewness.
  - Skewness reduced from **41.9** to **2.4**.

---

#### **4. Missing Value Imputation**
- **Imputation Strategy**:
  - Used group-based imputation to fill missing values in categorical and numerical columns.
  - For example:
    - `VehicleModel` was imputed based on `CylinderCount` and `capacity`.
    - `Brand` was imputed based on `VehicleModel`.
    - `ManufacturingYear` was imputed based on `Brand`, `VehicleModel`, and `CylinderCount`.
- **Imputation Functions**:
  - `compute_fill_values`: Computed imputation values from the training data.
  - `transform_test_data`: Applied the computed imputation values to both training and testing data.

---

#### **5. Preprocessing Pipeline**
- **Categorical Columns**:
  - Used `OneHotEncoder` to encode categorical columns (`Brand`, `VehicleModel`, `Type`, `color`, `fuel`, `type of gear`, `EngineSize`, `SafetyScore`).
- **Numerical Columns**:
  - Used `StandardScaler` to scale numerical columns (`ManufacturingYear`, `rating`, `Duty`, `CylinderCount`, `capacity`, `airbags`).
- **Yeo-Johnson Transformation**:
  - Applied Yeo-Johnson transformation and scaling to the `Odometer` column.
- **Pipeline**:
  - Combined all preprocessing steps into a single pipeline using `ColumnTransformer`.

---

#### **6. Preprocessing Results**
- **Training Data**:
  - All missing values were successfully imputed.
  - Categorical columns were one-hot encoded.
  - Numerical columns were scaled.
  - `Odometer` column was transformed to reduce skewness.
- **Testing Data**:
  - The same preprocessing steps were applied to the testing data using the transformations learned from the training data.

---
### Modeling Phase
---

#### **1. Model Selection and Evaluation**
- **Models Evaluated**:
  - **Linear Regression**
  - **SGDRegressor**
  - **Decision Tree Regressor**
  - **Random Forest Regressor**
  - **Support Vector Regressor (SVR)**
  - **Ridge Regression**
  - **Lasso Regression**
- **Evaluation Metrics**:
  - **Mean Absolute Error (MAE)**
  - **R-squared (R²)**
- **Results**:
  - **Random Forest Regressor** performed the best with an MAE of **6011.76** and an R² of **0.470**.
  - **SVR** performed the worst with an MAE of **9118.32** and a negative R².

---

#### **2. Hyperparameter Tuning for Random Forest**
- **Grid Search**:
  - Performed a grid search to find the best hyperparameters for the **Random Forest Regressor**.
  - **Best Parameters**:
    - `max_depth`: None
    - `max_features`: 'sqrt'
    - `min_samples_leaf`: 2
    - `min_samples_split`: 5
    - `n_estimators`: 200
- **Results**:
  - The tuned model achieved an MAE of **6495.23** and an R² of **0.430**.

---

#### **3. Ensemble Models**
- **Voting Regressor**:
  - Combined predictions from **LGBMRegressor**, **CatBoostRegressor**, **XGBRegressor**, and **GradientBoostingRegressor**.
  - Achieved an MAE of **6175.60**.
- **Stacking Regressor**:
  - Combined predictions from the same models as the Voting Regressor, with **LinearRegression** as the final estimator.
  - Achieved an MAE of **6179.01**.

---

#### **4. Enhanced Ensemble Models**
- **Added Extra Trees and Bagging**:
  - Enhanced the Stacking Regressor by adding **ExtraTreesRegressor** and **BaggingRegressor**.
  - Achieved an MAE of **5972.02**.
- **Added Random Forest**:
  - Further enhanced the Stacking Regressor by adding **RandomForestRegressor**.
  - Achieved an MAE of **5970.75**.
- **Voting Regressor with Additional Models**:
  - Combined predictions from all models, including **RandomForestRegressor**.
  - Achieved an MAE of **6177.18**.

---

#### **5. Summary of Results**
- **Best Performing Model**:
  - **Stacking Regressor** with **Extra Trees**, **Bagging**, and **Random Forest** achieved the lowest MAE of **5970.75**.
- **Comparison**:
  - **Random Forest Regressor**: MAE = **6011.76**, R² = **0.470**
  - **Tuned Random Forest Regressor**: MAE = **6495.23**, R² = **0.430**
  - **Voting Regressor**: MAE = **6175.60**
  - **Stacking Regressor**: MAE = **6179.01**
  - **Enhanced Stacking Regressor**: MAE = **5970.75**

---
### Model Evaluation and Test Submission

---

#### **1. Model Evaluation**
- **Best Model**:
  - **Stacking Regressor** with **Extra Trees**, **Bagging**, and **Random Forest** was selected as the best model based on its performance during cross-validation.
- **Evaluation on Test Set**:
  - The model was fitted on the training data and used to make predictions on the test set.
  - **Mean Absolute Error (MAE)** on the test set: **5477.63**.
  - This indicates that the model's predictions are, on average, within **$5477.63** of the actual prices.

---

#### **2. Test Submission**
- **Loading Test Data**:
  - The test data was loaded from the provided CSV file (`test.csv`).
  - The `ID` column was separated for the final submission.
- **Data Cleaning**:
  - Applied the same cleaning and preprocessing steps used for the training data:
    - **Brand**: Standardized brand names.
    - **VehicleModel**: Cleaned and standardized model names.
    - **ManufacturingYear**: Extracted and validated years.
    - **Type**: Standardized vehicle types.
    - **rating**: Ensured non-negative values.
    - **Duty**: Extracted numeric values from text.
    - **fuel**: Standardized fuel types.
    - **CylinderCount**: Extracted numeric values.
    - **type of gear**: Standardized gear types.
    - **capacity**: Extracted numeric values.
    - **Odometer**: Extracted numeric values.
    - **airbags**: Capped values between 0 and 12.
    - **EngineSize**: Categorized engine sizes into Small, Medium, and Large.
    - **SafetyScore**: Categorized airbags into Low, Medium, and High.
- **Missing Value Imputation**:
  - Used the `transform_test_data` function to impute missing values based on the imputation rules learned from the training data.
- **Preprocessing**:
  - Applied the same preprocessing pipeline (`full_pipeline_Preprocessing`) used for the training data to the test data.
- **Predictions**:
  - Used the trained **Stacking Regressor** to make predictions on the preprocessed test data.
- **Submission File**:
  - Created a submission file (`submission.csv`) with the `ID` and predicted `price` columns.
  - The file contains **3000 rows** of predictions.

---

#### **3. Submission File Preview**
- **Columns**:
  - `ID`: Unique identifier for each car.
  - `price`: Predicted price for each car.
- **Example Rows**:
  ```
  ID      price
  5634    9043.12
  16689   12963.42
  13457   11081.63
  4555    15573.44
  9726    9771.73
  ...
  ```

---

#### **4. Summary**
- **Model Performance**:
  - The **Stacking Regressor** achieved an MAE of **5477.63** on the test set, demonstrating strong predictive performance.
- **Test Submission**:
  - The test data was cleaned, preprocessed, and used to generate predictions.
  - The final submission file (`submission.csv`) is ready for submission.

---

