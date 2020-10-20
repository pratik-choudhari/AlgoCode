import styled from 'styled-components';
import { Button, Row, Col, Table } from 'antd';

const StyledClock = styled.div`
    border: 5px solid #DCFF03;
    height: 400px;
    width: 400px;
    box-sizing: border-box;
    background: #FFFFFF;
    box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    border-radius: 500px;
    display: flex;
    margin: 20px auto;
    justify-content: center;
    align-items: center;
`;

const StyledStartButton = styled(Button) `
    background: #FFFFFF;
    border: 3px solid #03FD2B;
    box-sizing: border-box;
    box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    border-radius: 60px;
    width: 250px;
    height: 100px;
    display: flex;
    align-items: center;
    justify-content: center; 
    margin: 50px auto;
    cursor: pointer;
    
    &:hover,
    &:focus {
        outline: none;

    }

    &:active {
        outline: none;
    }

    &[disabled] {
        cursor: not-allowed;
    }
`;

const StyledResetButton = styled(Button) `
    background: #FFFFFF;
    border: 3px solid #FF9A03;
    box-sizing: border-box;
    box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    border-radius: 60px;
    width: 250px;
    height: 100px;
    display: flex;
    align-items: center;
    justify-content: center; 
    cursor: pointer;
    margin-left: 20px;
    &:hover,
    &:focus {
        outline: none;

    }

    &:active {
        outline: none;
    }

    &[disabled] {
        cursor: not-allowed;
    }
`;
const StyledStopButton = styled(Button) `
background: #FFFFFF;
    border: 3px solid #FF0303;
    box-sizing: border-box;
    box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    border-radius: 60px;
    width: 250px;
    height: 100px;
    display: flex;
    align-items: center;
    justify-content: center; 
    cursor: pointer;
    
    &:hover,
    &:focus {
        outline: none;

    }

    &:active {
        outline: none;
    }

    &[disabled] {
        cursor: not-allowed;
    }`;

const StyledSpan = styled.span`
    font-size: 36px;
    line-height: 42px;
    text-align: center;
    letter-spacing: 0.14em;
    color: ${props => props.color};
    font-family: Roboto;
    font-weight: normal;
`;

const StyledDiv = styled.div`
    display: flex;
    flex-direction: column;
    align-items: center;
`;

const StyledRow = styled(Row) `
    display: flex;
    color: #DCFF03;
    align-items: center;
`;

const StyledCol = styled(Col) `
    margin-left: 20px;
`;

const StyledSecRow = styled(Row) `
    display: flex;
    color: #DCFF03;
    align-items: center;
    
`;

const StyledSecCol = styled(Col) `
    margin-left: 20px;
    margin-right: 20px;
`;

const StyledButtonRender = styled.div`
    margin: 50px auto;
    display: flex;
    align-items: center;
    justify-content: center;
`;

const StyledTable = styled(Table) `
    width: 100%;
`;

const StyledTableDiv = styled.div`
    margin: 50px auto;
    display: flex;
    align-items: center;
    justify-content: center;

`;

export { StyledClock, StyledStartButton, StyledTableDiv, StyledButtonRender, StyledSecRow, StyledSecCol, StyledRow, StyledCol, StyledDiv, StyledResetButton, StyledStopButton, StyledSpan, StyledTable };