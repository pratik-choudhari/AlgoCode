import React from 'react';
import PropTypes from 'prop-types';
import "antd/dist/antd.css";
import { StyledClock, StyledTable, StyledTableDiv, StyledButtonRender, StyledRow, StyledSecRow, StyledSecCol, StyledCol, StyledDiv, StyledStartButton, StyledResetButton, StyledStopButton, StyledSpan } from './styles';


class View extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            dataSource: [],
            key: 0,
        }
    }

    columns = [
        {
            title: 'Order',
            dataIndex: 'order',
            width: '50%',
            align: 'center'
        },
        {
            title: 'Time',
            dataIndex: 'time',
            width: '50%',
            align: 'center'
        }
    ]

    handleLap = (e) => {
        const [hrs, mins, secs, millisecs] = this.calculateTime(this.props.currentTime);
        const data = {
            key: this.state.key + 1,
            order: this.state.key + 1,
            time: `${hrs} ${mins} ${secs} ${millisecs}`
        }
        this.setState({ dataSource: [...this.state.dataSource, data], key: data.key });
    }

    calculateTime = (time) => {
        const hrs = Math.floor(time / (1000 * 60 * 60)).toString();
        const hrsStr = hrs.length === 1 ? `0${hrs}` : hrs;
        time = time % (1000 * 60 * 60);
        const mins = Math.floor(time / (1000 * 60)).toString();
        const minsStr = mins.length === 1 ? `0${mins}` : mins;
        time = time % (1000 * 60);
        const secs = Math.floor(time / (1000)).toString();
        const secsStr = secs.length === 1 ? `0${secs}` : secs;
        time = time % (1000);
        const millisecs = time.toString();
        const millisecsStr = millisecs.length === 1 ? `00${millisecs}` : millisecs.length === 2 ? `0${millisecs}` : millisecs;
        return [hrsStr, minsStr, secsStr, millisecsStr]
    }

    renderTime = (time) => {
        const [hrsStr, minsStr, secsStr, millisecsStr] = this.calculateTime(time);
        return (<StyledDiv>
            <StyledRow>
                <StyledCol>HRS</StyledCol>
                <StyledCol>MINS</StyledCol>
                <StyledCol>SECS</StyledCol>
                <StyledCol>MILLISECS</StyledCol>
            </StyledRow>
            <StyledSecRow>
                <StyledSecCol>{hrsStr}</StyledSecCol>
                <StyledSecCol>{minsStr}</StyledSecCol>
                <StyledSecCol>{secsStr}</StyledSecCol>
                <StyledSecCol>{millisecsStr}</StyledSecCol>
            </StyledSecRow>
        </StyledDiv>)
    }

    render() {
        return (
            <>
                <StyledClock onClick={this.handleLap}>
                    {this.renderTime(this.props.currentTime)}
                </StyledClock>

                {!this.props.isRunning && <StyledStartButton onClick={this.props.onStart}>
                    <StyledSpan color="#03FD2B"> START </StyledSpan>
                </StyledStartButton>}
                {this.props.isRunning && (
                    <StyledButtonRender>
                        <StyledStopButton onClick={this.props.onStop}>
                            <StyledSpan color="#FF0303">
                                STOP
                             </StyledSpan>
                        </StyledStopButton>
                        <StyledResetButton onClick={this.props.onReset}>
                            <StyledSpan color="#FF9A03">
                                RESET
                            </StyledSpan>
                        </StyledResetButton>
                    </StyledButtonRender>)}
                <StyledTableDiv>
                    <StyledTable
                        columns={this.columns}
                        pagination={false}
                        dataSource={this.state.dataSource}
                    />
                </StyledTableDiv>
            </>
        );
    }
}


View.propTypes = {
    onStart: PropTypes.func,
    onStop: PropTypes.func,
    onReset: PropTypes.func,
    currentTime: PropTypes.number,
    isRunning: PropTypes.bool,
}

View.defaultProps = {
    onStart: () => { },
    onStop: () => { },
    onReset: () => { },
    currentTime: 0,
    isRunning: false,
}

export default View;