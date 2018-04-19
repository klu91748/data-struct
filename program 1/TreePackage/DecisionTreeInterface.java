package TreePackage;

public interface DecisionTreeInterface<T> extends BinaryTreeInterface<T>
{

    T getCurrentData();
    void setCurrentData(T newData);
    void setResponses(T responseForNo, T responseForYes);
    boolean isAnswer();
    void advanceToNo();
    void advanceToYes();
    void resetCurrentNode();
}